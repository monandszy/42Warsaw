/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:34:47 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/30 12:34:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	process_heredoc_redir(t_cmd *curr, t_token *token)
{
	char	*cleaned;
	char	*expanded;

	cleaned = remove_quotes(token->next->value);
	expanded = read_heredoc(cleaned);
	redir_add_back(&curr->redirs, new_redir(token->type, expanded));
	free(cleaned);
	free(expanded);
}

void	process_file_redir(t_cmd *curr, t_token *token, t_shell *shell)
{
	char	*expanded;
	char	*cleaned;

	expanded = expand_str(token->next->value, shell);
	cleaned = remove_quotes(expanded);
	redir_add_back(&curr->redirs, new_redir(token->type, cleaned));
	free(cleaned);
	free(expanded);
}

void	process_redir(t_cmd *curr, t_token *token, t_shell *shell)
{
	if (token->next && token->next->type == TOKEN_WORD)
	{
		if (token->type == TOKEN_REDIR_HEREDOC)
			process_heredoc_redir(curr, token);
		else
			process_file_redir(curr, token, shell);
	}
	else
	{
    shperror("minishell", "syntax error near unexpected token");
		shell->exit_code = 258;
	}
}

void	process_word(t_cmd *curr, t_token *token, t_shell *shell)
{
	char	*expanded;
	char	*cleaned;

	expanded = expand_str(token->value, shell);
	cleaned = remove_quotes(expanded);
	add_cmd_arg(curr, cleaned);
	free(cleaned);
	free(expanded);
}
