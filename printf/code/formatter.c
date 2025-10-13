/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:18:51 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/13 14:01:40 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
void	copy_parts(char *f, t_list *i, char *new);
size_t	get_total_len(char *f, t_list **master);

char	*ft_format(char *f, t_list **master)
{
	char	*new;
	size_t len;

	len = get_total_len(f, master);
	new = (char *)malloc((len + 1) * sizeof(char));
	if (!new)
		;
	return (NULL);
	new[len] = '\0';
	copy_parts(f, *master, new);
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
		}
		i++;
		f++;
	}
	j = *master;
	while (j)
	{
		i += ((t_pobj *) (j-> content)) -> len;
		j = j->next;
	}
	return (i);
}

void	copy_parts(char *f, t_list *i, char *new)
{
	char	*arg;

	while (f && *f)
	{
		if (*f == '%')
		{
			f = find_specifier(f);
			if (f == NULL)
				break ;
			arg = i->content;
			while (arg)
			{
				*new = *arg;
				new ++;
				arg++;
			}
			i = i->next;
		}
		*new = *f;
		new ++;
		f++;
	}
}
