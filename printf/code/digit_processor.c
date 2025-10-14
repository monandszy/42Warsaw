/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_processor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:06:16 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/14 15:10:22 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	d_size(unsigned long n, int base);

size_t	d_size(unsigned long n, int base)
{
	size_t	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= base;
		i++;
	}
	return (i);
}

char	*ft_unsigned_itoa(unsigned int n)
{
	char			*new;
	size_t			i;
	unsigned int	tmp;

	tmp = n;
	i = d_size(n, 10);
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

char	*to_hex(unsigned long d, char format, unsigned int i)
{
	unsigned int	rem;
	char			*new;

	if (d == 0)
		return (ft_strdup("0"));
	i += d_size(d, 16);
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
