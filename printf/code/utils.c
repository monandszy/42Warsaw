/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:51:53 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/10 11:32:37 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const static char* g_flags = "#0- +.";

size_t count_args(char *f)
{
	size_t c;

	c = 0;
    while (*f)
    {
        if (*f == '%')
        {
			c++;
			while(*f++)
				if (!(*ft_strchr(g_flags, *f)))
					break ;
			if (!*f)
				return (c);
        }
        f++;
    }
    return (c);
}

