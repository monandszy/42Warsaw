/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:02:36 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/09 18:54:46 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static int	initialize_dlist(int **args, t_stack *a);

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
	(*a)->end->next = NULL;
	(*a)->e_count = argc;
	(*b)->e_count = 0;
	return (0);
}

static int	initialize_dlist(int **args, t_stack *a)
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
