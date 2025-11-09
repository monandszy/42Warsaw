/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:47:37 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 14:47:44 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
