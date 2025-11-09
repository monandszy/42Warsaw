/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_calculator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:03:51 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 13:03:53 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_dlist	*calculate_all_rrr_moves(t_stack *from, t_stack *to)
{
	int		to_index;
	int		from_index;
	t_dlist	*moves_list;
	t_dlist	*current_node;
	t_move	*cost;

	if (!from || !from->end)
		return (NULL);
	moves_list = NULL;
	current_node = from->end;
	from_index = 1;
	while (current_node)
	{
		to_index = calculate_rr_move(*((int *)(current_node->content)), to);
		cost = calculate_negative_cost(from_index, to_index);
		if (!cost)
		{
			return (NULL);
		}
		ft_dlstadd_back(&moves_list, ft_dlstnew(cost));
		from_index++;
		current_node = current_node->prev;
	}
	return (moves_list);
}

t_move	*calculate_optimal_rrr_cost(t_stack *from, t_stack *to)
{
	int		to_index;
	int		from_index;
	t_dlist	*i;
	t_move	*min_cost;
	t_move	*cost;

	min_cost = NULL;
	i = from->end;
	from_index = 1;
	while (i)
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
