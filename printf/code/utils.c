/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:51:53 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/10 18:24:56 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const static char	*g_flags = "#0- +.";
const static char	*g_specifiers = "cspdiuxX";

/*char **alloc_args(char *f)
{
	size_t	c;
	char	**master;
	int		i;

	c = 0;
	f = find_specifier(f);
	while (f != NULL)
	{
		f = find_specifier(f);
		c++;
	}
	master = (char **) malloc(sizeof(char *) * (c + 1));
	if (!master)
		return (NULL);
	master[c] = NULL;
	return (master);
}*/
char	*find_trigger(char *f)
{
	int i;

	i = 0;
	while (f[i])
	{
		if (f[i] == '%')
			return (&f[i]);
		i++;
	}
	return (NULL);
}

char	*find_specifier(char *f)
{
	int	i;

	f = find_trigger(f);
	if (f == NULL)
		return (NULL);
	i = 0;
	while (f[++i])
	{
		if (!ft_strchr(g_flags, f[i]))
			return (&f[i]);
	}
	return (NULL);
}
