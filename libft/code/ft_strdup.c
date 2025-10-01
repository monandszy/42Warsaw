/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:37:31 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/29 10:42:32 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	int		l;
	int		i;
	char	*new;

	i = 0;
	l = ft_strlen(src);
	new = (char *)malloc((l + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	while (i < l)
	{
		new[i] = src[i];
		i++;
	}
	new[l] = '\0';
	return (new);
}
