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
