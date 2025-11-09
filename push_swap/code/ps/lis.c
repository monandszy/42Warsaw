/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 13:37:39 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	calc_lis(int **int_args, int argc, int *counters,
				int *predecessors);
static void	extract_max(int argc, int *schema, int *counters,
				int *predecessors);

int	execute_lis(int *schema, t_dlist **steps, t_stack *a, t_stack *b)
{
	size_t	i;
	size_t	total;

	i = 0;
	total = a->e_count;
	while (i < total)
	{
		if (schema[i] == 1)
			*steps = ra(*steps, a);
		else
			*steps = pb(*steps, a, b);
		if (!*steps)
			return (-1);
		i++;
	}
	return (i);
}

int	*lis(int **int_args, int argc)
{
	int	*counters;
	int	*predecessors;
	int	*schema;

	counters = (int *)malloc(sizeof(int) * argc);
	predecessors = (int *)malloc(sizeof(int) * argc);
	schema = (int *)ft_calloc(argc, sizeof(int));
	if (!counters || !predecessors || !schema)
		return (free(counters), free(predecessors), free(schema), NULL);
	calc_lis(int_args, argc, counters, predecessors);
	extract_max(argc, schema, counters, predecessors);
	free(counters);
	free(predecessors);
	return (schema);
}

static void	calc_lis(int **int_args, int argc, int *counters, int *predecessors)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		counters[i] = 1;
		predecessors[i] = -1;
		j = 0;
		while (j < i)
		{
			if (int_args[j][0] < int_args[i][0] && counters[j]
				+ 1 > counters[i])
			{
				counters[i] = counters[j] + 1;
				predecessors[i] = j;
			}
			j++;
		}
		i++;
	}
}

static void	extract_max(int argc, int *schema, int *counters, int *predecessors)
{
	int	max_c;
	int	i;

	max_c = 0;
	i = 1;
	while (i < argc)
	{
		if (counters[i] > counters[max_c])
			max_c = i;
		i++;
	}
	i = max_c;
	while (i != -1)
	{
		schema[i] = 1;
		i = predecessors[i];
	}
}
