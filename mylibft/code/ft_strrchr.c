/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:29:16 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/24 18:15:16 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strrchr(const char *s, int c)
{
	char	*last;
	char	*i;
	char	needle;

	needle = (char)c;
	last = NULL;
	i = (char *)s;
	while (*i != '\0')
	{
		if (*i == needle)
			last = i;
		i++;
	}
	if (needle == '\0' && *i == '\0')
		return (i);
	if (last)
		return (last);
	else
		return (NULL);
}
