/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:38:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/10 19:44:22 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int optimal_sort(t_dlist **steps, t_stack *a, t_stack *b)
{
	t_dlist *start;

    *steps = ft_dlstnew(ft_strdup("INIT"));
    start = *steps;
	if (a -> e_count == 3)
	{
		if (sort_3(steps, a))
			return (f_dl(start), 1);
	}
	else if (a -> e_count == 4)
	{
		if (sort_4(steps, a, b))
			return (f_dl(start), 1);
	}
	else if (a -> e_count == 5)
	{
		if (sort_5(steps, a, b))
			return (f_dl(start), 1);
	}
	*steps = start;
	return (0);
}

int sort_3(t_dlist **steps, t_stack *a)
{
	t_dlist *st;
	t_dlist *nd;
	t_dlist *rd;
	
	st = a -> start;
	nd = st -> next;
	rd = nd -> next;
	if (*(int *) st -> content > *(int *) nd -> content)
	{
		*steps = sa(*steps, a);
		if (!*steps)
			return (1);
	}
	if (*(int *) nd -> content > *(int *) rd -> content)
	{
		*steps = rra(*steps, a);
		if (!*steps)
			return (1);
	  if (*(int *) rd -> content > *(int *) st -> content)
		{
			*steps = sa(*steps, a);
			if (!*steps)
				return (1);
		}
	}
	return (0);
}

int sort_4(t_dlist **steps, t_stack *a, t_stack *b)
{
	if (adjust_order(steps, a, 0))
		return (1);
	*steps = pb(*steps, a, b);
	if (!*steps)
		return (1);
  if (is_sorted(a, 1))
  {
    if (adjust_order(steps, a, 1))
      return (1);
  }
	else if (sort_3(steps, a))
		return (1);
	*steps = pa(*steps, a, b);
	if (!*steps)
		return (1);
	return (0);
}

int sort_5(t_dlist **steps, t_stack *a, t_stack *b)
{
	if (adjust_order(steps, a, 0))
		return (1);
  *steps = pb(*steps, a, b);
	if (!*steps)
		return (1);
	if (adjust_order(steps, a, 1))
		return (1);
  *steps = pb(*steps, a, b);
	if (!*steps)
		return (1);
	if (is_sorted(a, 2))
  {
    if (adjust_order(steps, a, 2))
      return (1);
  }
	else if (sort_3(steps, a))
		return (1);
	*steps = pa(*steps, a, b);
	if (!*steps)
		return (1);
	*steps = pa(*steps, a, b);
	if (!*steps)
		return (1);
	return (0);
}
