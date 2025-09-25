/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 10:39:22 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/24 12:55:47 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// append src to dst
// if size > 0
// returns len of dst + src.   
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t l1;
	size_t l2;
    unsigned int i;

	l1 = ft_strlen(dst);
	l2 = ft_strlen(src);
    i = 0;

    if (size == 0)
        return(l2);
	
    while (src[i] && (l1 + i < size - 1))
    {
        dst[l1 + i] = src[i];
        i++;
    }
	if (l1 > size)
		return (l2 + size);		
   	dst[l1 + i] = '\0';
    return (l1 + l2);
}

