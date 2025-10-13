/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:51:53 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/13 13:52:14 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const static char	*g_flags = "#0- +.";

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
		if (!ft_strchr(g_flags, t[i]))
			return (&t[i]);
		i++;
	}
	return (NULL);
}
