
#include "ps.h"

int	main(int argc, char **argv)
{
	char	**args;
	t_dlist	*steps;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	steps = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
	{
		args = ft_split(*argv, ' ');
		if (!args || validate_argv(args))
			return (f_sp(args), ft_printf("Error\n"), 1);
	}
	else
		return (ft_printf("Error\n"), 1);
	if (initialize_stack(args, a, b))
		return (f_sp(args), f_st(a), f_st(b), ft_printf("Error\n"), 1);
	if (plan(steps, a, b))
		return (f_sp(args), f_st(a), f_st(b), f_dl(steps), ft_printf("Error\n"), 1);
  print_steps(steps);
	return (f_sp(args), f_st(a), f_st(b), f_dl(steps),
		0);
}

void	print_steps(t_dlist *steps)
{
	t_dlist *i;

	i = steps;
	while (i)
	{
		ft_printf("%s\n", (char *)i->content);
		i = i->next;
	}
}