#include "ps.h"

int	initialize_stack(char **args, t_stack **a, t_stack **b, int argc)
{
	int	**int_args;

	int_args = NULL;
	*a = (t_stack *)malloc(sizeof(t_stack));
	*b = (t_stack *)malloc(sizeof(t_stack));
	if (!a || !b || to_int_arr(args, &int_args, argc)
		|| initialize_dlist(int_args, *a))
		return (1);
	bubble_sort(int_args);
	initialize_targets(int_args, *a);
	free(int_args);
	(*a)->size = argc;
	(*b)->size = 0;
	return (0);
}

int	to_int_arr(char **args, int ***int_args, int argc)
{
	int	res;
  int *tmp;

	*int_args = (int **)malloc(sizeof(int *) * (argc + 1));
	if (!*int_args)
		return (1);
	int_args[0][argc] = NULL;
  argc--;
	while (argc >= 0)
	{
    tmp = (int *) malloc(sizeof(int));
		res = ft_atoi(args[argc]);
    *tmp = res;
		int_args[0][argc] = tmp;
		argc--;
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
	prev->content = args[0];
	a->start = prev;
	i = 1;
	while (args[i])
	{
		new = (t_dlist *)malloc(sizeof(t_dlist));
		if (!new)
			return (1);
		new->content = args[i];
		new->prev = prev;
		prev->next = new;
		prev = new;
		i++;
	}
	a->end = prev;
	return (0);
}