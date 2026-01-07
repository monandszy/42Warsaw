/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:34:47 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/30 12:34:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_shlvl;

static char	*join_hd_line(char *content, char *line)
{
	char	*tmp;
	char	*new_content;

	tmp = ft_strjoin(content, line);
	free(content);
	new_content = ft_strjoin(tmp, "\n");
	free(tmp);
	return (new_content);
}

char	*read_heredoc(char *del)
{
	char	*line;
	char	*res;

	res = ft_strdup("");
	g_shlvl = -1;
	while (1)
	{
		line = readline("> ");
		if (g_shlvl == 0)
			return (free(res), NULL);
		if (!line)
		{
			shperror("minishell", "while looking for delimiter");
			break ;
		}
		if (ft_strncmp(line, del, ft_strlen(del) + 1) == 0)
			break ;
		res = join_hd_line(res, line);
		free(line);
	}
	if (line)
		free(line);
	return (g_shlvl = 0, res);
}
