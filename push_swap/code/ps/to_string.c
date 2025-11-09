/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:03:58 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 16:48:56 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

/* void	print_move(t_move *move)
{
	printf("move:[shared: %d, to_i: %d, from_i: %d, cost: %d]\n", move->shared,
		move->to_index, move->from_index, move->cost);
	fflush(stdout);
}

void	print_stack(t_stack *stack)
{
	t_dlist	*i;

	printf("%s", "stack:[");
	i = stack->start;
	while (i)
	{
		printf("(%d)", *((int *)(i->content)));
		i = i->next;
	}
	printf("%s", "]\n");
	fflush(stdout);
}

void	print_dlist(t_dlist **dl)
{
	t_dlist	*i;

	printf("%s", "dlist:[");
	i = *dl;
	while (i)
	{
		printf("(%s)", ((char *)(i->content)));
		i = i->next;
	}
	printf("%s", "]\n");
	fflush(stdout);
}

void	print_lis_from_stack(t_stack *stack, int *lis_schema)
{
	t_dlist	*n_i;
	size_t	i;
	int		value;

	n_i = stack->start;
	i = 0;
	printf("LIS elements: ");
	while (n_i && i < stack->e_count)
	{
		if (lis_schema[i] == 1)
		{
			value = *(int *)(n_i->content);
			printf("%d ", value);
		}
		n_i = n_i->next;
		i++;
	}
	printf("\n");
}

void	print_int_arr(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void	print_int_matrice(int **arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", arr[i][0]);
	}
	printf("\n");
}

void	print_dlist_moves(t_dlist **dl)
{
	t_dlist	*i;

	printf("%s", "dlist:[");
	i = *dl;
	while (i)
	{
		print_move((t_move *)i->content);
		i = i->next;
	}
	printf("%s", "]\n");
	fflush(stdout);
} */
