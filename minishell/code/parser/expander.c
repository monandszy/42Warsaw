/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_expander.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:34:47 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/30 12:34:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expand_str(char *str, t_shell *shell)
{
	char	*res;
	int		i;
	char	quote;

	res = NULL;
	i = 0;
	quote = '\0';
	while (str[i])
	{
		update_quote(str[i], &quote);
		if (str[i] == '$' && quote != '\'')
			res = process_dollar(res, str, &i, shell);
		else
		{
			res = join_char(res, str[i]);
			i++;
		}
	}
	if (!res)
		return (ft_strdup(""));
	return (res);
}
