/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pusher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:29 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 13:04:36 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	push(t_stack *to, t_stack *from)
{
	t_dlist	*fnode;
	t_dlist	*tnode;

	tnode = to->start;
	fnode = from->start;
	if (!fnode)
		return ;
	if (fnode == from->end)
		from->end = NULL;
	if (fnode->next)
		fnode->next->prev = NULL;
	from->start = fnode->next;
	fnode->prev = NULL;
	fnode->next = tnode;
	if (tnode)
		tnode->prev = fnode;
	if (!to->end)
		to->end = fnode;
	to->start = fnode;
	from->e_count--;
	to->e_count++;
}

t_dlist	*pa(t_dlist *steps, t_stack *a, t_stack *b)
{
	if (b->e_count == 0)
		return (steps);
	push(a, b);
	steps->next = ft_dlstnew(ft_strdup("pa"));
	steps->next->prev = steps;
	return (steps->next);
}

t_dlist	*pb(t_dlist *steps, t_stack *a, t_stack *b)
{
	if (a->e_count == 0)
		return (steps);
	push(b, a);
	steps->next = ft_dlstnew(ft_strdup("pb"));
	steps->next->prev = steps;
	return (steps->next);
}
