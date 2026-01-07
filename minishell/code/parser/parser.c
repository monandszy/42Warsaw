/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:34:09 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/30 14:01:52 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_redir_token(t_token_type type)
{
	return (type == TOKEN_REDIR_IN || type == TOKEN_REDIR_OUT
		|| type == TOKEN_REDIR_APPEND || type == TOKEN_REDIR_HEREDOC);
}

static t_cmd	*new_cmd(t_cmd **head, t_shell *shell)
{
	t_cmd	*curr;

	curr = init_cmd();
	if (!curr)
		end(shell, "new_cmd malloc error");
	cmd_add_back(head, curr);
	return (curr);
}

static void	parser_error(t_shell *shell)
{
	shperror("minishell", "syntax error near unexpected token");
	shell->exit_code = 2;
}

static int	handle_token(t_token **token, t_cmd **curr, t_cmd **head,
		t_shell *shell)
{
	if ((*token)->type == TOKEN_PIPE)
	{
		if (!(*curr)->args && !(*curr)->redirs)
			return (parser_error(shell), 0);
		*curr = new_cmd(head, shell);
	}
	else if (is_redir_token((*token)->type))
	{
		if (process_redir(*curr, *token, shell) || shell->exit_code == 2)
			return (0);
		if ((*token)->next)
			*token = (*token)->next;
	}
	else if ((*token)->type == TOKEN_WORD)
		process_word(*curr, *token, shell);
	return (1);
}

t_cmd	*parse_tokens(t_token *token, t_shell *shell)
{
	t_cmd	*head;
	t_cmd	*curr;

	if (token && token->type == TOKEN_PIPE)
		return (parser_error(shell), NULL);
	head = NULL;
	curr = new_cmd(&head, shell);
	while (token)
	{
		if (!handle_token(&token, &curr, &head, shell))
			return (free_cmds(head), NULL);
		if (token)
			token = token->next;
	}
	if (!curr->args && !curr->redirs && head->next)
		return (parser_error(shell), free_cmds(head), NULL);
	return (head);
}
