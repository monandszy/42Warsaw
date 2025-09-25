/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 19:54:07 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/25 16:08:44 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void *ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char *dsti;
	unsigned char *srci;
	unsigned long tmp;
	int flag;

	dsti = (unsigned char *) dest;
    srci = (unsigned char *) src;
	tmp = n;

	flag = 0;
	while (tmp > 0)
	{
		if (srci == (unsigned char *) dest)
		{
			flag = 1;
		}
		srci++;
		tmp--;
	}

	if (flag == 0)
		ft_memcpy(dest, src, n);
	else if (flag == 1)
	{
		srci = (unsigned char *) src;
		while (n > 0)
		{
			dsti[n - 1] = srci[n - 1];
			n--;
		}
	}
	return (dest);
}
