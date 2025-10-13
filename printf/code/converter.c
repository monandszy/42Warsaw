/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:13:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/13 13:55:51 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_c(char *str)
{
	char	*c;

	c = (char *)malloc(sizeof(char) * 2);
	c[0] = *str;
	c[1] = '\0';
	return (c);
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
	d[0] = '%';
	d[1] = '\0';
	return (d);
}
