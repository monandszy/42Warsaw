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

void	assign_move(t_move *new, int a_index, int b_index);

t_move	*calculate_cost(t_stack *a, t_stack *b, int a_index, int b_index)
{
	t_move	*new;

	new = (t_move *)malloc(sizeof(t_move));
	if (!new)
		return (NULL);
	if (a_index > a->e_count / 2)
		a_index = (a->e_count - a_index) * -1;
	if (b_index > b->e_count / 2)
		b_index = (b->e_count - b_index) * -1;
	assign_move(new, a_index, b_index);
	return (new);
}

void	assign_move(t_move *new, int a_index, int b_index)
{
	if ((a_index >= 0 && b_index >= 0) || (a_index <= 0 && b_index <= 0))
	{
		if (a_index >= 0)
			new->shared = min(a_index, b_index);
		else
			new->shared = max(a_index, b_index);
		new->to_index = a_index - new->shared;
		new->from_index = b_index - new->shared;
		new->cost = abs(new->shared) + abs(new->to_index)
			+ abs(new->from_index);
	}
	else
	{
		new->shared = 0;
		new->to_index = a_index;
		new->from_index = b_index;
		new->cost = abs(new->to_index) + abs(new->from_index);
	}
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
