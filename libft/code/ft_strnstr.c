/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 18:27:24 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/24 19:27:53 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	char *hay = (char *) big;
	char *ndl = (char *) little;
	char *res;
	int flag;
	
	flag = 1;
	res = hay;
	if (*ndl == '\0')
		return (res);

	while (*hay != '\0' && len > 0)
	{
		if (*hay == *ndl)
		{
			if (flag == 1)
			{
				res = hay;
				flag = 0;
			}
			ndl++;
			if (*ndl == '\0')
				return (res);
		}
		else
		{
			ndl = (char *) little;
			if (flag == 0)
			{
				flag = 1;
				continue;
			}
		}
		len--;
		hay++;
	}
	return (NULL);
}
