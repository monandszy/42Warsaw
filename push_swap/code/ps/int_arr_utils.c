/* ************************************************************************** */
/*																			*/
/*														:::		::::::::   */
/*   int_arr_utils.c                                    :+:      :+:    :+:   */
/*													+:+ +:+			+:+		*/
/*   By: sandrzej <sandrzej@student.42.fr>			+#+  +:+		+#+		*/
/*												+#+#+#+#+#+   +#+			*/
/*   Created: 2025/11/09 13:10:24 by sandrzej			#+#	#+#				*/
/*   Updated: 2025/11/09 13:23:40 by sandrzej         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "ps.h"

static int	process_loop(int i, int argc, int **indexes, int **args)
{
	int	j;
	int	min;
	int	min_i;
	int	*tmp;

	min = 2147483647;
	j = 0;
	while (j < argc)
	{
		if (min >= (args)[j][0])
		{
			min = (args)[j][0];
			min_i = j;
		}
		j++;
	}
	tmp = (int *)malloc(sizeof(int));
	if (!tmp)
		return (1);
	*tmp = i;
	indexes[min_i] = tmp;
	(args)[min_i][0] = 2147483647;
	return (0);
}

int	indexify(int ***args, int argc)
{
	int	i;
	int	**indexes;

	indexes = (int **)malloc(sizeof(int *) * (argc + 1));
	if (!indexes)
		return (1);
	i = 0;
	while (i <= argc)
	{
		indexes[i] = NULL;
		i++;
	}
	i = 0;
	while (i < argc)
	{
		if (process_loop(i, argc, indexes, args[0]))
			return (free_int_matrix(indexes, argc), 1);
		i++;
	}
	free_int_matrix(*args, argc);
	*args = indexes;
	return (0);
}

int	to_int_arr(char **args, int ***int_args, int argc)
{
	int	res;
	int	*tmp;

	int_args[0] = (int **)malloc(sizeof(int *) * (argc + 1));
	if (!*int_args)
		return (1);
	int_args[0][argc] = NULL;
	argc--;
	while (argc >= 0)
	{
		tmp = (int *)malloc(sizeof(int));
		res = ft_atoi(args[argc]);
		*tmp = res;
		int_args[0][argc] = tmp;
		argc--;
	}
	return (0);
}
