/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:16 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 16:24:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	plan(int *schema, t_dlist **steps, t_stack *a, t_stack *b)
{
	t_dlist	*start;
	int		cost;
	int		res;

	if (a->e_count <= 1)
		return (0);
	*steps = ft_dlstnew(ft_strdup("INIT"));
	start = *steps;
	if (!*steps)
		return (1);
	cost = execute_lis(schema, steps, a, b);
	free(schema);
	res = fsr(steps, a, b, cost);
	if (res == 1)
	{
		while (b->e_count > 0)
			execute_optimal_move(steps, a, b);
		adjust_order_move(steps, a, 0);
	}
	if (res == -1)
		return (1);
	*steps = start;
	return (0);
}

int	transfer(t_dlist **steps, t_stack *a, t_stack *b)
{
	int	cost;

	cost = a->e_count;
	while (a->e_count > 0)
		*steps = pb(*steps, a, b);
	return (cost);
}
