/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:06 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 16:11:46 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_dlist	*pop(t_dlist *steps)
{
	t_dlist	*tmp;

	if (steps)
	{
		tmp = steps;
		if (steps->prev)
		{
			steps = steps->prev;
			steps->next = NULL;
		}
		f_dl(tmp);
	}
	return (steps);
}

void	ft_dlstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*i;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	i = *lst;
	while (i->next != NULL)
		i = i->next;
	i->next = new;
	new->prev = i;
}

t_dlist	*dlst_merge(t_dlist *first, t_dlist *second)
{
	t_dlist	*main;

	if (!first)
	{
		main = second;
		return (main);
	}
	main = first;
	while (first->next)
		first = first->next;
	first->next = second;
	second->prev = first;
	return (main);
}
