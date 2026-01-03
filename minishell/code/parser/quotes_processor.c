/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:34:47 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/30 14:01:52 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	check_unclosed_quote(char *line)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (line[i])
	{
		if (!quote && (line[i] == '\'' || line[i] == '\"'))
			quote = line[i];
		else if (quote && line[i] == quote)
			quote = 0;
		i++;
	}
	return (quote);
}

char	*remove_quotes(char *str)
{
	char	*res;
	int		i;
	char	quote;

	res = NULL;
	i = 0;
	quote = 0;
	while (str[i])
	{
		if (!quote && (str[i] == '\'' || str[i] == '\"'))
			quote = str[i];
		else if (quote && str[i] == quote)
			quote = 0;
		else
			res = join_char(res, str[i]);
		i++;
	}
	if (!res)
		return (ft_strdup(""));
	return (res);
}
