/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:13:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/13 16:59:10 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return (strdup(str));
}

char	*to_hex(unsigned long d, char format, unsigned int i)
{
	char			c;
	char			*str;
	unsigned int	rem;

	rem = d % 16;
	if (rem > 0)
	{
		if (rem >= 0 && rem <= 9)
			c = '0' + rem;
		else if (rem >= 10 && rem <= 15)
			c = format + (rem % 10);
		to_hex(d / 16, format, ++i);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * (i + 1));
		if (str == NULL)
			return (NULL);
		str[i] = '\0';
		return (str);
	}
	str[i] = c;
	return (str);
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
