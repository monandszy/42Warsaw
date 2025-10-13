/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:13:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/13 17:34:22 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char    *to_hex(unsigned long d, char format, unsigned int i);

char	*to_c(int c)
{
	char *s;

	s = (char *) malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	s[0] = (char) c;
	s[1] = '\0';
	return (s);
}

char	*to_s(char *str)
{
	if (str == NULL)
		str = "(null)";
	return (ft_strdup(str));
}

char *to_xXp(unsigned long d, char format)
{
	if (d == 0)
	{
		return (ft_strdup("0"));
	}
	return (to_hex(d, format, -1));
}

char	*to_hex(unsigned long d, char format, unsigned int i)
{
	unsigned long tmp;
	unsigned int rem;
	char		*new;
	size_t len;

	tmp = d;
	i = 0;
	while (tmp > 0)
	{	
		tmp = tmp / 16;
		i++;
	}
	new = (char *) malloc(sizeof(char) * (i + 1));
	if (new == NULL)
		return (NULL);
	new[i] = '\0';
	i--;
	while (d > 0)
	{
		rem = d % 16;
		if (rem >= 0 && rem <= 9)
			new[i] = '0' + rem;
		else if (rem >= 10 && rem <= 15)
			new[i] = format + (rem % 10);
		d /= 16;
		i--;
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
