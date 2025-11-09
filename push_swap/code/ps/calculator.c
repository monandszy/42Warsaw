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

t_move	*calculate_cost(int from_index, int to_index)
{
	t_move	*new;

	new = (t_move *)malloc(sizeof(t_move));
	if (!new)
		return (NULL);
	if (from_index >= to_index)
	{
		new->shared = to_index;
		new->to_index = 0;
		new->from_index = from_index - to_index;
		new->cost = new->shared + new->from_index;
	}
	else
	{
		new->shared = from_index;
		new->from_index = 0;
		new->to_index = to_index - from_index;
		new->cost = new->shared + new->to_index;
	}
	return (new);
}

t_move	*calculate_negative_cost(int from_index, int to_index)
{
	t_move	*new;

	new = (t_move *)malloc(sizeof(t_move));
	if (!new)
		return (NULL);
	if (from_index >= to_index)
	{
		new->shared = -to_index;
		new->to_index = 0;
		new->from_index = -(from_index - to_index);
		new->cost = ft_abs(new->shared) + ft_abs(new->from_index);
	}
	else
	{
		new->shared = -from_index;
		new->from_index = 0;
		new->to_index = -(to_index - from_index);
		new->cost = ft_abs(new->shared) + ft_abs(new->to_index);
	}
	return (new);
}

int	ft_abs(int i)
{
	if (i < 0)
		i = -i;
	return (i);
}

int	ft_greater(int i1, int i2)
{
	if (i1 < i2)
		return (i2);
	return (i1);
}

int	ft_lower(int i1, int i2)
{
	if (i1 > i2)
		return (i2);
	return (i1);
}
