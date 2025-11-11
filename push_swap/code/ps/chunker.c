/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:02:36 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/10 15:48:24 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int	get_target_from_chunk(t_stack *a, int start, int end, int best_cost)
{
	t_dlist	*i;
	int		best_target;
	int		a_index;
	int		cost;

	i = a->start;
	best_target = -1;
	a_index = 0;
	while (a_index < a->e_count)
	{
		cost = a_index++;
		if (*(int *)i->content >= start && *(int *)i->content < end)
		{
			if (a_index > a->e_count / 2)
				cost = a->e_count - a_index;
			if (best_target == -1 || cost < best_cost)
			{
				best_cost = cost;
				best_target = *(int *)i->content;
			}
		}
		i = i->next;
	}
	return (best_target);
}

int	push_chunk(t_data *data, int start, int end, int chunk_size)
{
	int		e_pushed;
	t_dlist	**steps;
	t_stack	*a;
	t_stack	*b;

	steps = data->steps;
	a = data->a;
	b = data->b;
	e_pushed = 0;
	while (e_pushed < (chunk_size) && a->e_count > 0)
	{
		adjust_order(steps, a, get_target_from_chunk(a, start, end, -1));
		*steps = pb(*steps, a, b);
		if (!*steps)
			return (1);
		if (b->e_count > 1 && *(int *)b->start->content < (start + (chunk_size
					/ 2)))
			*steps = rb(*steps, b);
		if (!*steps)
			return (1);
		e_pushed++;
	}
	return (0);
}

int	push_chunks(t_data *data)
{
	int	num_chunks;
	int	chunk_size;
	int	i;
	int	start;
	int	end;

	num_chunks = 1 + data->a->e_count / 200;
	chunk_size = data->a->e_count / num_chunks;
	i = 0;
	while (i < num_chunks)
	{
		start = i * chunk_size;
		end = (i + 1) * chunk_size;
		if (push_chunk(data, start, end, chunk_size))
			return (1);
		i++;
	}
	return (0);
}
