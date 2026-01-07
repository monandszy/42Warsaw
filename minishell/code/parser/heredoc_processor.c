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

char	*read_heredoc(char *delimiter)
{
	char	*line;
	char	*content;
	char	*tmp;

	content = ft_strdup("");
  g_shlvl = -1;
	while (1)
	{
		line = readline("> ");
    if (g_shlvl == 0)
      return (free(content), NULL);
		if (!line)
    {
      shperror("minishell", "while looking for delimiter");
      break ;
    }
		if (ft_strncmp(line, delimiter, ft_strlen(delimiter) + 1) == 0)
		{
			free(line);
			break ;
		}
		tmp = content;
		content = ft_strjoin(content, line);
		free(tmp);
		tmp = content;
		content = ft_strjoin(content, "\n");
		free(tmp);
		free(line);
	}
  g_shlvl = 0;
	return (content);
}
