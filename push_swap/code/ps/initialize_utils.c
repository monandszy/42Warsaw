#include "ps.h"

char	**argv_split(char **argv, int argc)
{
	char	**spl;

	spl = (char **)malloc((argc + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	spl[argc] = NULL;
	argc--;
	while (argc >= 0)
	{
		spl[argc] = argv[argc];
		argc--;
	}
	return (spl);
}

int	initialize_stack(int ***args, t_stack **a, t_stack **b, int argc)
{
	*a = (t_stack *)malloc(sizeof(t_stack));
	*b = (t_stack *)malloc(sizeof(t_stack));
	(*a)->start = NULL;
	(*a)->end = NULL;
	(*b)->start = NULL;
	(*b)->end = NULL;
	if (indexify(args, argc) || !a || !b || initialize_dlist(*args, *a))
		return (1);
	(*a)->e_count = argc;
	(*b)->e_count = 0;
	return (0);
}

int	indexify(int ***args, int argc)
{
	int	i;
	int	j;
	int	min_i;
	int	min;
	int	**indexes;
	int	*tmp;

	indexes = (int **)malloc(sizeof(int *) * (argc + 1));
	if (!indexes)
		return (1);
	indexes[argc] = NULL;
	i = 0;
	while (i < argc)
	{
		min = 2147483647;
		j = 0;
		while (j < argc)
		{
			if (min >= (args)[0][j][0])
			{
				min = (args)[0][j][0];
				min_i = j;
			}
			j++;
		}
		fflush(stdout);
		tmp = (int *)malloc(sizeof(int));
		*tmp = i;
		indexes[min_i] = tmp;
		(args)[0][min_i][0] = 2147483647;
		i++;
	}
	free_int_matrix(*args, argc);
	*args = indexes;
	return (0);
}

int	initialize_dlist(int **args, t_stack *a)
{
	t_dlist	*prev;
	t_dlist	*new;
	int		i;

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

int	to_int_arr(char **args, int ***int_args, int argc)
{
	int res;
	int *tmp;

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