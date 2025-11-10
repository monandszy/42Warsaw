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

int is_sorted(t_stack *a);

int sorted(t_dlist **steps, t_stack *a)
{
	t_dlist *start;

	if (!is_sorted(a))
		return (0);
    *steps = ft_dlstnew(ft_strdup("INIT"));
    start = *steps;
	if (!*steps || adjust_order(steps, a))
		return (f_dl(start), 0);
	*steps = start;
	return (1);
}

int is_sorted(t_stack *a)
{
	t_dlist *i;
	t_dlist *prev;
	int target;

	prev = a -> start;
	i = prev -> next;
	if (!i)
		i = a -> start;
    target = *(int *) prev;
    while (1==1)
    {
        if (*(int *) i -> content == target)
            return (1);
        if (*(int *) prev -> content > *(int *) i -> content)
        {
            target = *(int *) prev;
            break ;
        }
        prev = i;
        i = i -> next;
        if (!i)
            i = a -> start;
    }
	while (*(int *) i -> content != target)
	{
		if (*(int *) prev -> content > *(int *) i -> content)
			return (0);
		prev = i;
		i = i -> next;
		if (!i)
			i = a -> start;
	}
	return (1);
}

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
	t_dlist *st;
	t_dlist *nd;
	t_dlist *rd;
	t_dlist *th;

	st = a -> start;
	nd = st -> next;
	rd = nd -> next;
	th = rd -> next;

	adjust_order(steps, a);
    *steps = pb(*steps, a, b);
	print_stack(a);
	if (is_sorted(a))
		 adjust_order(steps, a);
	else
		sort_3(steps, a);
	print_stack(a);
	execute_optimal_move(steps, a, b);
	print_stack(a);
	return (0);
}

int sort_5(t_dlist **steps, t_stack *a, t_stack *b)
{
	t_dlist *st;
	t_dlist *nd;
	t_dlist *rd;
	t_dlist *th;
	t_dlist *fth;

	st = a -> start;
	nd = st -> next;
	rd = nd -> next;
	th = rd -> next;
	fth = th -> next;
	print_stack(b);
	(void) steps;
	return (0);
}
