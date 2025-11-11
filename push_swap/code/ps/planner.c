/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:16 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/10 16:57:24 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

// execute_lis(schema, steps, a, b);
// if (transfer(steps, a, b))
//   return (1);
int	plan(t_dlist **steps, t_stack *a, t_stack *b)
{
	t_data	*data;
	t_dlist	*start;

	*steps = ft_dlstnew(ft_strdup("INIT"));
	start = *steps;
	if (!*steps)
		return (1);
	data = (t_data *)malloc(sizeof(t_data));
	data->steps = steps;
	data->a = a;
	data->b = b;
	if (push_chunks(data))
		return (free(data), 1);
	while (b->e_count > 0)
		if (execute_optimal_move(steps, a, b))
			return (free(data), 1);
	if (adjust_order(steps, a, 0))
		return (free(data), 1);
	*steps = start;
	return (free(data), 0);
}

int	transfer(t_dlist **steps, t_stack *a, t_stack *b)
{
	while (a->e_count > 0)
	{
		*steps = pb(*steps, a, b);
		if (!*steps)
			return (1);
	}
	return (0);
}
