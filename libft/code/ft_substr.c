/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:50:38 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/29 11:50:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int i;
	size_t olen;
	char *substr;

	olen = ft_strlen(s);

	len = olen - start;
	if (len <= 0)
		return (malloc(0));
	
	i = 0;
	substr = (char *) malloc (len + 1);
	if (substr == NULL)
		return (NULL);
	substr[len + 1] = '\0';
	ft_memcpy(substr, &s[start], len);

	return (substr);
}
