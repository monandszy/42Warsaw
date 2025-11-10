/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:03:51 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 14:22:58 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_move	*calculate_optimal_rrr_cost(t_stack *from, t_stack *to)
{
	int	to_index;
	int	from_index;
	t_dlist	*i;
	t_move	*min_cost;
	t_move	*cost;

	min_cost = NULL;
	i = from->end;
	from_index = 1;
	while (i && from_index <= (from->e_count + to->e_count) / 2)
	{
		to_index = calculate_rr_move(*((int *)(i->content)), to);
		cost = calculate_negative_cost(from_index, to_index);
		if (!min_cost || cost->cost < min_cost->cost)
		{
			free(min_cost);
			min_cost = cost;
		}
		else
			free(cost);
		from_index++;
		i = i->prev;
	}
	return (min_cost);
}

int	calculate_rr_move(int target, t_stack *s)
{
	t_dlist	*i;
	int		closest_target;
	int		diff;
	int		ctfrom_index;
	int		index;

	index = 1;
	closest_target = 0;
	ctfrom_index = 0;
	i = s->end;
	while (i)
	{
		diff = target - *((int *)(i->content));
		if (ft_abs(diff) <= closest_target || closest_target == 0)
		{
			ctfrom_index = index;
			if (diff > 0)
				ctfrom_index--;
			closest_target = ft_abs(diff);
		}
		index++;
		i = i->prev;
	}
	return (ctfrom_index);
}
