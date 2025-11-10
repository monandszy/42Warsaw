/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:38:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/10 19:44:22 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int is_sorted(t_stack *a, int min)
{
	t_dlist	*prev;
	t_dlist	*i;

	prev = a->start;
	while (*(int *)prev->content != min)
		prev = prev->next;
	i = prev->next;
	if (!i)
		i = a->start;
	while (*(int *)i->content != min)
	{
		if (*(int *)prev->content > *(int *)i->content)
			return (0);
		prev = i;
		i = i->next;
		if (!i)
			i = a->start;
	}
	return (1);
}

int sorted(t_dlist **steps, t_stack *a)
{
	t_dlist	*start;

  if (!is_sorted(a, 0))
    return (0);
	*steps = ft_dlstnew(ft_strdup("INIT"));
	if (!*steps)
		return (0);
	start = *steps;
	if (adjust_order(steps, a, 0))
      return (f_dl(start), 0);
	*steps = start;
	return (1);
}