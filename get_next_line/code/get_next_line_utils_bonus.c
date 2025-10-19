/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:09:45 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/15 14:09:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* void	free_buffer(t_buffer *data, t_buffer *i)
{
	t_buffer	*tmp;
	t_buffer	*prev;

	tmp = i;
	if (tmp->fd == data->fd)
	{
		tmp = data->next;
		free(data);
		i = tmp;
		return ;
	}
	prev = NULL;
	while (tmp)
	{
		if (tmp->fd == data->fd)
		{
			prev->next = tmp->next;
			free(tmp->content);
			free(tmp);
		}
		prev = tmp;
		tmp = tmp->next;
	}
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	olen;
	char	*substr;

	if (s == NULL)
		return (NULL);
	olen = ft_strlen(s);
	if (start > olen)
		return (NULL);
	if (olen - start < len)
		len = olen - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	substr[len] = '\0';
	ft_memcpy(substr, &s[start], len);
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;
	char	*new;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		l1 = 0;
	else
		l1 = ft_strlen(s1);
	if (s2 == NULL)
		l2 = 0;
	else
		l2 = ft_strlen(s2);
	new = (char *)malloc((l1 + l2 + 1) * sizeof(char));
	if (new)
	{
		new[l1 + l2] = '\0';
		ft_memcpy(new, s1, l1);
		ft_memcpy(&new[l1], s2, l2);
	}
	return (new);
}

size_t	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i])
			i++;
	}
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*srci;
	unsigned char	*dsti;

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

size_t	ft_strchr(char *s, char needle)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == needle)
			return (++i);
		i++;
	}
	return (0);
} */
