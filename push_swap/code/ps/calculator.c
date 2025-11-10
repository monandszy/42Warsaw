/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:06:48 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 13:06:50 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

t_move	*calculate_cost(t_stack *a, t_stack *b, int a_index, int b_index)
{
  t_move	*new;
	int		cost_a;
	int		cost_b;

	new = (t_move *)malloc(sizeof(t_move));
	if (!new)
		return (NULL);
	cost_a = (a_index <= a->e_count / 2) ? a_index : (a->e_count - a_index) * -1;
	cost_b = (b_index <= b->e_count / 2) ? b_index : (b->e_count - b_index) * -1;

	if ((cost_a >= 0 && cost_b >= 0) || (cost_a <= 0 && cost_b <= 0))
	{
		if (cost_a >= 0) 
			new->shared = min(cost_a, cost_b);
		else
			new->shared = max(cost_a, cost_b);
		new->to_index = cost_a - new->shared;
		new->from_index = cost_b - new->shared;
		new->cost = abs(new->shared) + abs(new->to_index) + abs(new->from_index);
	}
	else
	{
		new->shared = 0;
		new->to_index = cost_a;
		new->from_index = cost_b;
		new->cost = abs(new->to_index) + abs(new->from_index);
	}
	return (new);
}

int	abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

int	max(int i1, int i2)
{
	if (i1 < i2)
		return (i2);
	return (i1);
}

int	min(int i1, int i2)
{
	if (i1 > i2)
		return (i2);
	return (i1);
}
