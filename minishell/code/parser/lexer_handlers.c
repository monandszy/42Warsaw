/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:34:47 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/30 12:34:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_pipe(int *i, t_token **head)
{
	token_add_back(head, new_token(ft_strdup("|"), TOKEN_PIPE));
	(*i)++;
}

void	handle_redir_in(char *line, int *i, t_token **head)
{
	if (line[*i + 1] == '<')
	{
		token_add_back(head, new_token(ft_strdup("<<"), TOKEN_REDIR_HEREDOC));
		(*i) += 2;
	}
	else
	{
		token_add_back(head, new_token(ft_strdup("<"), TOKEN_REDIR_IN));
		(*i)++;
	}
}

void	handle_redir_out(char *line, int *i, t_token **head)
{
	if (line[*i + 1] == '>')
	{
		token_add_back(head, new_token(ft_strdup(">>"), TOKEN_REDIR_APPEND));
		(*i) += 2;
	}
	else
	{
		token_add_back(head, new_token(ft_strdup(">"), TOKEN_REDIR_OUT));
		(*i)++;
	}
}

void	handle_separator(char *line, int *i, t_token **head)
{
	if (line[*i] == '|')
		handle_pipe(i, head);
	else if (line[*i] == '<')
		handle_redir_in(line, i, head);
	else if (line[*i] == '>')
		handle_redir_out(line, i, head);
}
