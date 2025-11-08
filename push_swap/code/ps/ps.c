
#include "ps.h"

int	main(int argc, char **argv)
{
  char **args;
  int **int_args;
	t_dlist	*steps;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	steps = NULL;
  int_args = NULL;
	if (argc == 1)
		return (0);
  args = argv_split(++argv, --argc);
  if (!args || validate_argv(args))
    return (free(args), ft_printf("Error\n"), 1);
	if (to_int_arr(args, &int_args, argc) || initialize_stack(&int_args, &a, &b, argc))
		return (free(int_args), free(args), f_st(a), f_st(b), ft_printf("Error\n"), 1);
	if (plan(lis(int_args, argc), &steps, a, b))
  // if (radix(&steps, a, b))
		return (free(int_args), free(args), f_st(a), f_st(b), f_dl(steps), ft_printf("Error\n"), 1);
  print_steps(steps);
	return (free(int_args), free(args), f_st(a), f_st(b), f_dl(steps), 0);
}

void	print_steps(t_dlist *steps)
{
	t_dlist *i;

	i = steps;
  if (!i)
    return;
  i = i->next;
	while (i)
	{
		ft_printf("%s\n", (char *)i->content);
		i = i->next;
	}
}