/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 16:07:53 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static t_dlist	*calculate_sorted_moves(t_stack *a, t_stack *b);
static int		get_direction(t_stack *a);

int	fsr(t_dlist **steps, t_stack *a, t_stack *b, size_t total_cost)
{
	t_dlist	*i;
	t_dlist	*all;
	t_move	*current_move;
	int		res;

	if (((total_cost) > ((a->e_count + b->e_count) * (6 + (a->e_count
						+ b->e_count) / 100) - 1)))
		return (1);
	if (b->e_count == 0)
		return (adjust_order_move(steps, a, total_cost));
	all = calculate_sorted_moves(a, b);
	if (!all)
		return (-1);
	i = all;
	while (i)
	{
		current_move = (t_move *)i->content;
		execute_move(steps, a, b, current_move);
		res = fsr(steps, a, b, total_cost + current_move->cost + 1);
		if (res < 1)
			return (f_dl(all), res);
		reverse_move(steps, a, b, current_move);
		i = i->next;
	}
	return (f_dl(all), 1);
}

static t_dlist	*calculate_sorted_moves(t_stack *a, t_stack *b)
{
	t_dlist	*rr_moves;
	t_dlist	*rrr_moves;
	t_dlist	*all;

	rr_moves = calculate_all_rr_moves(b, a);
	rrr_moves = calculate_all_rrr_moves(b, a);
	if (!rr_moves || !rrr_moves)
		return (f_dl(rr_moves), f_dl(rrr_moves), NULL);
	all = dlst_merge(rr_moves, rrr_moves);
	dlst_sort(&all);
	return (all);
}

int	adjust_order_move(t_dlist **steps, t_stack *a, size_t total_cost)
{
	size_t	res;

	res = get_direction(a);
	if (((total_cost + ft_abs(res)) < (a->e_count * (6 + (a->e_count) / 100)
				- 1)))
	{
		if (res > 0)
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

static int	get_direction(t_stack *a)
{
	size_t	cs;
	size_t	ce;
	t_dlist	*i;

	cs = 0;
	ce = 0;
	i = a->start;
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
	if (cs - ce < 0)
		return (-cs);
	else
		return (ce);
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
