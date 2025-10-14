/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 11:13:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/14 12:45:51 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*to_c(int c)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 2);
	if (s == NULL)
		return (NULL);
	if (c == 0)
		c = 1;
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

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*new;
	size_t			i;
	unsigned int	tmp;

	tmp = n;
	i = 0;
	if (tmp == 0)
		i = 1;
	while (tmp > 0)
	{
		tmp /= 10;
		i++;
	}
	new = (char *)malloc((i + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[i] = '\0';
	i--;
	if (n == 0)
		new[i] = '0';
	while (n > 0)
	{
		new[i] = (char)((n % 10) + '0');
		n /= 10;
		i--;
	}
	return (new);
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

char	*to_hex(unsigned long d, char format, unsigned int i)
{
	unsigned long	tmp;
	unsigned int	rem;
	char			*new;

	if (d == 0)
		return (ft_strdup("0"));
	tmp = d;
	while (tmp > 0)
	{
		tmp = tmp / 16;
		i++;
	}
	new = (char *)malloc(sizeof(char) * (i + 1));
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
