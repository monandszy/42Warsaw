/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:51:53 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/14 13:39:26 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*find_trigger(char *f)
{
	int	i;

	if (f == NULL)
		return (NULL);
	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
			return (&f[i]);
		i++;
	}
	return (NULL);
}

char	*find_specifier(char *t)
{
	int	i;

	if (t == NULL || *t == '\0')
		return (NULL);
	t++;
	i = 0;
	while (t[i])
	{
		if (!ft_strchr("#0- +.", t[i]) && !ft_isdigit(t[i]))
			return (&t[i]);
		i++;
	}
	return (NULL);
}
