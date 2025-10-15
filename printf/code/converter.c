/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:13:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/14 17:01:03 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_c(int c)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	s[0] = (char)c;
	s[1] = '\0';
	return (s);
}

char	*to_s(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (ft_strdup(str));
}

char	*to_p(void *p)
{
	char			*new;
	unsigned long	d;

	if (!p)
		return (ft_strdup("(nil)"));
	else
	{
		d = (unsigned long)p;
		if (d == 0)
			return (ft_strdup("0x0"));
		new = to_hex(d, 'a', 2);
		new[0] = '0';
		new[1] = 'x';
	}
	return (new);
}

char	*get_default(void)
{
	char	*d;

	d = (char *)malloc(sizeof(char) * 2);
	if (d == NULL)
		return (NULL);
	d[0] = '%';
	d[1] = '\0';
	return (d);
}
