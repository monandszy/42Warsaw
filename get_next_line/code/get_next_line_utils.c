/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:09:35 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/17 16:04:31 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char    *ft_strjoin(char **s1, char **s2, size_t l2)
{
    size_t  l1;
    char    *new;

    if (*s1 == NULL && *s2 == NULL)
        return (NULL);
    if (*s1 == NULL)
        l1 = 0;
    else
        l1 = ft_strlen(*s1);
    if (*s2 == NULL)
        l2 = 0;
    new = (char *)malloc((l1 + l2 + 1) * sizeof(char));
    if (new)
	{
    	new[l1 + l2] = '\0';
	    ft_memcpy(new, *s1, l1);
	    ft_memcpy(&new[l1], *s2, l2);
	}
	if (s1 && *s1)
	{
		printf("{NULL: %s}", *s1);
		free (*s1);
	}
    return (new);
}

size_t  ft_strlen(const char *s)
{
    unsigned int    i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

void    *ft_memcpy(void *dest, const void *src, size_t n)
{
    unsigned char   *srci;
    unsigned char   *dsti;

    dsti = (unsigned char *)dest;
    srci = (unsigned char *)src;
    while (n > 0)
    {
        *dsti = *srci;
        dsti++;
        srci++;
        n--;
    }
    return (dest);
}

char    *ft_strchr(char *s, char needle)
{
    char    *i;

	if (s == NULL)
		return (NULL);
    i = s;
    while (*i)
    {
        if (*i == needle)
            return (i);
        i++;
    }
    if (needle == '\0' && *i == '\0')
        return (i);
    return (NULL);
}

