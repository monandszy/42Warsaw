/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefix_creator_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 16:54:29 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/23 16:54:39 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*create_prefix(t_pobj *pobj)
{
	char	*prefix;
	char	sign;

	prefix = NULL;
	sign = 0;
	if (ft_strchr("di", pobj->specifier))
	{
		if (pobj->content[0] == '-')
		{
			sign = '-';
			if (deminus_content(pobj))
				return (NULL);
		}
		else
		{
			if (pobj->plus_padding == 1)
				sign = '+';
			if (pobj->spc_padding == 1)
				sign = ' ';
		}
		if (sign != 0)
		{
			prefix = (char *)malloc(sizeof(char) * (2));
			if (!prefix)
				return (NULL);
			prefix[0] = sign;
			prefix[1] = '\0';
			ft_strlcpy(prefix, &sign, 2);
		}
	}
	else if (pobj->alt_type == 1 && ft_strchr("xX", pobj->specifier)
		&& (pobj->len != 1 || pobj->content[0] != '0'))
	{
		prefix = (char *)malloc(sizeof(char) * (3));
		if (!prefix)
			return (NULL);
		prefix[0] = '0';
		prefix[1] = pobj->specifier;
		prefix[2] = '\0';
	}
	return (prefix);
}

int	deminus_content(t_pobj *pobj)
{
	char	*new_content;

	new_content = ft_strdup(pobj->content + 1);
	if (!new_content)
		return (1);
	free(pobj->content);
	pobj->content = new_content;
	pobj->len = pobj->len - 1;
	return (0);
}
