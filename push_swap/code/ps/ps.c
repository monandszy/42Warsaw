/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:05:10 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 18:54:39 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

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
	if (argc == 1)
		return (0);
	args = argv_split(++argv, --argc);
	if (!args || validate_argv(args))
		return (free(args), write(STDERR_FILENO, "Error\n", 6), 1);
	if (to_int_arr(args, &int_args, argc) || initialize_stack(&int_args, &a, &b,
			argc))
		return (free(int_args), free(args), f_st(a), f_st(b),
			write(STDERR_FILENO, "Error\n", 6), 1);
	if (plan(lis(int_args, argc), &steps, a, b))
		return (free(int_args), free(args), f_st(a), f_st(b), f_dl(steps),
			write(STDERR_FILENO, "Error\n", 6), 1);
	print_steps(steps);
	return (free(int_args), free(args), f_st(a), f_st(b), f_dl(steps), 0);
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
