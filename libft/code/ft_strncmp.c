/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:12:32 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/24 14:14:17 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n)
{
    unsigned int    i;

    i = 0;
    while (i < n)
    {
        if (s1[i] == '\0' && s2[i] == '\0')
            return (0);
        else if (s1[i] < s2[i])
            return (s1[i] - s2[i]);
        else if (s1[i] > s2[i])
            return (s1[i] - s2[i]);
        i++;
    }
    return (0);
}
