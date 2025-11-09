/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 14:15:57 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	find_solution_recursive(t_dlist **steps, t_stack *a, t_stack *b,
		size_t total_cost)
{
	t_dlist	*rr_moves;
	t_dlist	*rrr_moves;
	t_dlist	*i;
	t_dlist	*all;
	t_move	*current_move;

	if (((total_cost) > ((a->e_count + b->e_count) * (6 + 4 + (a->e_count
						+ b->e_count) / 100) - 1)))
		return (1);
	if (b->e_count == 0)
		return (adjust_order_move(steps, a, total_cost));
	rr_moves = calculate_all_rr_moves(b, a);
	rrr_moves = calculate_all_rrr_moves(b, a);
	i = dlst_merge(rr_moves, rrr_moves);
	all = i;
	dlst_sort(&i);
	while (i)
	{
		current_move = (t_move *)i->content;
		execute_move(steps, a, b, current_move);
		if (find_solution_recursive(steps, a, b, total_cost + current_move->cost
				+ 1) == 0)
		{
			f_dl(all);
			return (0);
		}
		reverse_move(steps, a, b, current_move);
		i = i->next;
	}
	f_dl(all);
	return (1);
}

int	adjust_order_move(t_dlist **steps, t_stack *a, size_t total_cost)
{
	size_t	cs;
	size_t	ce;
	size_t	res;
	t_dlist	*i;

	i = a->start;
	cs = 0;
	ce = 0;
	while (i && i->next
		&& *((int *)(i->content)) < *((int *)(i->next->content)))
	{
		cs++;
		i = i->next;
	}
	i = a->end;
	while (i && i->prev
		&& *((int *)(i->content)) > *((int *)(i->prev->content)))
	{
		ce++;
		i = i->prev;
	}
	res = ft_lower(ce, cs);
	if (((total_cost + res) < (a->e_count * (6 + 4 + (a->e_count) / 100) - 1)))
	{
		if (cs > ce)
			while (*((int *)(a->start->content)) > *((int *)(a->end->content)))
				*steps = rra(*steps, a);
		else
			while (*((int *)(a->start->content)) > *((int *)(a->end->content)))
				*steps = ra(*steps, a);
		return (0);
	}
	else
		return (1);
}

int	reverse_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
	int	tmp;

	push(b, a);
	*steps = pop(*steps);
	tmp = move->shared;
	while (tmp < 0)
	{
		rotate(a);
		rotate(b);
		*steps = pop(*steps);
		tmp++;
	}
	tmp = move->from_index;
	while (tmp < 0)
	{
		rotate(b);
		*steps = pop(*steps);
		tmp++;
	}
	tmp = move->to_index;
	while (tmp < 0)
	{
		rotate(a);
		*steps = pop(*steps);
		tmp++;
	}
	tmp = move->shared;
	while (tmp > 0)
	{
		rrotate(a);
		rrotate(b);
		*steps = pop(*steps);
		tmp--;
	}
	tmp = move->from_index;
	while (tmp > 0)
	{
		rrotate(b);
		*steps = pop(*steps);
		tmp--;
	}
	tmp = move->to_index;
	while (tmp > 0)
	{
		rrotate(a);
		*steps = pop(*steps);
		tmp--;
	}
	return (0);
}

int	execute_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
	int	tmp;

	tmp = move->shared;
	while (tmp < 0)
	{
		*steps = rrr(*steps, a, b);
		tmp++;
	}
	tmp = move->from_index;
	while (tmp < 0)
	{
		*steps = rrb(*steps, b);
		tmp++;
	}
	tmp = move->to_index;
	while (tmp < 0)
	{
		*steps = rra(*steps, a);
		tmp++;
	}
	tmp = move->shared;
	while (tmp > 0)
	{
		*steps = rr(*steps, a, b);
		tmp--;
	}
	tmp = move->from_index;
	while (tmp > 0)
	{
		*steps = rb(*steps, b);
		tmp--;
	}
	tmp = move->to_index;
	while (tmp > 0)
	{
		*steps = ra(*steps, a);
		tmp--;
	}
	*steps = pa(*steps, a, b);
	return (0);
}

int	execute_optimal_move(t_dlist **steps, t_stack *a, t_stack *b)
{
	int		cost;
	t_move	*rr_move;
	t_move	*rrr_move;

	rr_move = calculate_optimal_rr_cost(b, a);
	rrr_move = calculate_optimal_rrr_cost(b, a);
	if (!rr_move || !rrr_move)
		return (free(rr_move), free(rrr_move), 1);
	if (rrr_move->cost > rr_move->cost)
	{
		if (execute_move(steps, a, b, rr_move))
			return (free(rr_move), free(rrr_move), -1);
		cost = rr_move->cost;
	}
	else
	{
		if (execute_move(steps, a, b, rrr_move))
			return (free(rr_move), free(rrr_move), -1);
		cost = rrr_move->cost;
	}
	return (free(rr_move), free(rrr_move), cost);
}
