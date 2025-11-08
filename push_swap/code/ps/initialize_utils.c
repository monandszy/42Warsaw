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

int	initialize_stack(int **args, t_stack **a, t_stack **b, int argc)
{
	*a = (t_stack *) malloc(sizeof(t_stack));
	*b = (t_stack *) malloc(sizeof(t_stack));
	if (!a || !b || initialize_dlist(args, *a))
		return (1);
	(*a)->e_count = argc;
	(*b)->e_count = 0;
	return (0);
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