/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reverser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:25:06 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 16:08:09 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	reverse_rrr(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
	int	tmp;

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
}

static void	reverse_rr(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
	int	tmp;

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
}

int	reverse_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
	push(b, a);
	*steps = pop(*steps);
	reverse_rr(steps, a, b, move);
	reverse_rrr(steps, a, b, move);
	return (0);
}
