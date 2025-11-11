/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:05:10 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/10 18:12:34 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	pass(int **int_args, char **args, t_stack *a, t_stack *b);
static int	error(int **int_args, char **args, t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	char	**args;
	int		**int_args;
	t_dlist	*steps;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	steps = NULL;
	int_args = NULL;
	if (argc <= 2)
		return (0);
	args = argv_split(++argv, --argc);
	if (!args || validate_argv(args))
		return (free(args), write(2, "Error\n", 6), 1);
	if (to_int_arr(args, &int_args, argc) || i_stack(&int_args, &a, &b, argc))
		return (error(int_args, args, a, b));
	if (sorted(&steps, a))
		;
	else if (a->e_count <= 5 && optimal_sort(&steps, a, b))
		return (f_dl(steps), error(int_args, args, a, b));
	else if (a->e_count > 5 && plan(lis(int_args, argc), &steps, a, b))
		return (f_dl(steps), error(int_args, args, a, b));
	return (print_steps(steps), f_dl(steps), pass(int_args, args, a, b));
}

static int	pass(int **int_args, char **args, t_stack *a, t_stack *b)
{
	free(int_args);
	free(args);
	f_st(a);
	f_st(b);
	return (0);
}

static int	error(int **int_args, char **args, t_stack *a, t_stack *b)
{
	free(int_args);
	free(args);
	f_st(a);
	f_st(b);
	write(2, "Error\n", 6);
	return (1);
}

void	print_steps(t_dlist *steps)
{
	t_dlist	*i;

	i = steps;
	if (!i)
		return ;
	i = i->next;
	while (i)
	{
		ft_printf("%s\n", (char *)i->content);
		i = i->next;
	}
}
