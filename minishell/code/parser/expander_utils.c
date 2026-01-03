/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:34:47 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/30 12:34:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_env_val(t_shell *shell, char *key)
{
	char	*val;

	if (ft_strncmp(key, "?", 2) == 0)
		return (ft_itoa(shell->exit_code));
	val = env_get(&shell->env_list, key);
	if (val)
		return (ft_strdup(val));
	return (NULL);
}

void	update_quote(char c, char *quote)
{
	if (!*quote && (c == '\'' || c == '\"'))
		*quote = c;
	else if (*quote && c == *quote)
		*quote = 0;
}

char	*append_exit_code(char *res, t_shell *shell, int *i)
{
	char	*val;

  val = ft_itoa(shell->exit_code);
	res = ft_strjoin_free(res, val);
	free(val);
	(*i)++;
	return (res);
}

char	*append_variable(char *res, char *str, int *i, t_shell *shell)
{
	int		start;
	char	*key;
	char	*val;

	start = *i;
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		(*i)++;
	key = ft_substr(str, start, *i - start);
	val = get_env_val(shell, key);
	if (val)
	{
		res = ft_strjoin_free(res, val);
		free(val);
	}
	free(key);
	return (res);
}

char	*process_dollar(char *res, char *str, int *i, t_shell *shell)
{
	(*i)++;
	if (str[*i] == '?')
		return (append_exit_code(res, shell, i));
	else if (ft_isalnum(str[*i]) || str[*i] == '_')
		return (append_variable(res, str, i, shell));
	else
		return (join_char(res, '$'));
}
