#include "ps.h"

int	initialize_stack(char **args, t_stack *a, t_stack *b)
{
	int	a_size;
	int	**int_args;

	int_args = NULL;
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	a_size = (((long)sizeof(args)) / ((long)sizeof(args[0])));
	if (!a || !b || to_int_arr(args, int_args, a_size)
		|| initialize_dlist(int_args, a))
		return (1);
	bubble_sort(int_args);
	initialize_targets(int_args, a);
	free(int_args);
	a->size = a_size;
	b->size = 0;
	return (0);
}

int	to_int_arr(char **args, int **int_args, int a_size)
{
	int	res;

	int_args = (int **)malloc(sizeof(int *) * a_size);
	if (!int_args)
		return (1);
	a_size--;
	int_args[a_size] = NULL;
	while (a_size >= 0)
	{
		res = ft_atoi(args[a_size]);
		int_args[a_size] = &res;
		a_size--;
	}
	return (0);
}

void	bubble_sort(int **args)
{
	int	i;
	int	*prev;
	int	*current;
	int	*tmp;
	int	is_sorted;

	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		i = 1;
		while (args[i])
		{
			prev = args[i - 1];
			current = args[i];
			if (*prev > *current)
			{
				tmp = prev;
				prev = current;
				current = tmp;
				is_sorted = 0;
			}
			i++;
		}
	}
}

void	initialize_targets(int **args, t_stack *a)
{
	t_dlist	*i;
	int		j;

	i = a->start;
	while (i)
	{
		j = 0;
		while (args[j])
		{
			if (*(args[j]) == *((int *)(i->content)))
			{
				i->target = j;
				break ;
			}
			j++;
		}
		i = i->next;
	}
}

int	initialize_dlist(int **args, t_stack *a)
{
	t_dlist *prev;
	t_dlist *new;
	int i;

	prev = (t_dlist *)malloc(sizeof(t_dlist));
	if (!prev)
		return (1);
	prev->content = &args[0][0];
	a->start = prev;
	i = 1;
	while (args[i])
	{
		new = (t_dlist *)malloc(sizeof(t_dlist));
		if (!new)
			return (1);
		new->content = &args[i][0];
		new->prev = prev;
		prev->next = new;
		prev = new;
		i++;
	}
	a->end = prev;
	return (0);
}