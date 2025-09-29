/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 11:50:38 by sandrzej          #+#    #+#             */
/*   Updated: 2025/09/29 17:19:27 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int i;
	size_t olen;
	char *substr;

	olen = ft_strlen(s);
	if (start > olen)
		return (NULL);
	if (olen - start < len)
		len = olen - start;
		
	i = 0;
	substr = (char *) malloc (len + 1);
	if (substr == NULL)
		return (NULL);
	substr[len] = '\0';
	return(ft_memcpy(substr, &s[start], len));
}
