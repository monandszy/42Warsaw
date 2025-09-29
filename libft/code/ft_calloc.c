/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:50:14 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/29 10:42:11 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// malloc, free
void *ft_calloc(size_t nmemb, size_t size)
{
	char *i;
	int b;

	b = size * nmemb;
	if (b <= 0 || (b / nmemb != size))
		return (malloc(0));

	i = (char *) malloc(b);
	if (i == NULL)
		return (NULL);
	ft_bzero(i, size);
	return ((void *) i);
}
