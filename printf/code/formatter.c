/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:18:51 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/13 16:47:23 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		copy_parts(char *f, t_list *i, char *new);
static size_t	get_total_len(char *f, t_list **master);

char	*ft_format(char *f, t_list **master, int *len)
{
	char	*new;

	*len = get_total_len(f, master);
	new = (char *)malloc((*len + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new[*len] = '\0';
	if (copy_parts(f, *master, new) == 1)
		*len = -1;
	return (new);
}

size_t	get_total_len(char *f, t_list **master)
{
	size_t	i;
	t_list	*j;

	i = 0;
	while (f && *f)
	{
		if (*f == '%')
		{
			f = find_specifier(f);
			if (f == NULL)
				break ;
			f++;
			continue ;
		}
		i++;
		f++;
	}
	j = *master;
	while (j)
	{
		i += ((t_pobj *)(j->content))->len;
		j = j->next;
	}
	return (i);
}

int	copy_parts(char *f, t_list *i, char *new)
{
	char	*arg;

	while (f && *f)
	{
		if (*f == '%')
		{
			f = find_specifier(f);
			if (f == NULL)
				return (1);
			f++;
			arg = ((t_pobj *)i->content)->content;
			while (*arg)
			{
				*new = *arg;
				new ++;
				arg++;
			}
			i = i->next;
			continue ;
		}
		*new = *f;
		new ++;
		f++;
	}
	return (0);
}
