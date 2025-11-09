/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_executor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 14:47:37 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 16:24:26 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	execute_rr_rrr(t_dlist **steps, t_stack *a, t_stack *b,
		t_move *move)
{
	int	tmp;

	tmp = move->shared;
	while (tmp < 0)
	{
		*steps = rrr(*steps, a, b);
		if (!*steps)
			return (1);
		tmp++;
	}
	tmp = move->shared;
	while (tmp > 0)
	{
		*steps = rr(*steps, a, b);
		if (!*steps)
			return (1);
		tmp--;
	}
	return (0);
}

static int	execute_rrb_rra(t_dlist **steps, t_stack *a, t_stack *b,
		t_move *move)
{
	int	tmp;

	tmp = move->from_index;
	while (tmp < 0)
	{
		*steps = rrb(*steps, b);
		if (!*steps)
			return (1);
		tmp++;
	}
	tmp = move->to_index;
	while (tmp < 0)
	{
		*steps = rra(*steps, a);
		if (!*steps)
			return (1);
		tmp++;
	}
	return (0);
}

static int	execute_ra_rb(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
	int	tmp;

	tmp = move->from_index;
	while (tmp > 0)
	{
		*steps = rb(*steps, b);
		if (!*steps)
			return (1);
		tmp--;
	}
	tmp = move->to_index;
	while (tmp > 0)
	{
		*steps = ra(*steps, a);
		if (!*steps)
			return (1);
		tmp--;
	}
	return (0);
}

int	execute_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
	if (execute_rr_rrr(steps, a, b, move) || execute_rrb_rra(steps, a, b, move)
		|| execute_ra_rb(steps, a, b, move))
		return (1);
	*steps = pa(*steps, a, b);
	return (0);
}
