/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/10 19:04:55 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int		find_origin(t_stack *a, int min);

int	adjust_order(t_dlist **steps, t_stack *a, int min)
{
  int target;
  
  target = find_origin(a, min);
  if (target <= a->e_count / 2)
  {
    while (target-- > 0)
    {
      *steps = ra(*steps, a);
      if (!*steps)
        return (1);
    }
  }
  else
  {
    while (target++ < a->e_count) 
    {
        *steps = rra(*steps, a);
        if (!*steps)
          return (1);
    }
  }
  return (0);
}

int find_origin(t_stack *stack, int min)
{
    t_dlist *i;
    int index;

    i = stack->start;
    index = 0;
    while (i)
    {
        if (*(int *) i->content == min)
            return (index);
        i = i->next;
        index++;
    }
    return (-1);
}

int	execute_optimal_move(t_dlist **steps, t_stack *a, t_stack *b)
{
  t_move *best;
  best = get_optimal_move(a, b);
  if (!best)
    return (1);
  if (execute_move(steps, a, b, best))
    return (free(best), 1);
	return (free(best), 0);
}

t_move	*get_optimal_move(t_stack *to, t_stack *from)
{
	int	to_index;
	int	from_index;
	t_dlist	*i;
	t_move	*best;
	t_move	*move;

	best = NULL;
	i = from->start;
	from_index = 0;
	while (i)
	{
		to_index = get_a_index(*(int *)i->content, to);
		move = calculate_cost(to, from, to_index, from_index);
		if (!best || move->cost < best->cost)
		{
			free(best);
			best = move;
		}
		else
			free(move);
		from_index++;
		i = i->next;
	}
	return (best);
}

int	get_a_index(int target, t_stack *s)
{
	t_dlist	*i;
	int		closest_target;
	int		diff;
	int		ctfrom_index;
	int		index;

	index = 0;
	closest_target = 0;
	ctfrom_index = 0;
	i = s->start;
	while (i)
	{
		diff = target - *((int *)(i->content));
		if (abs(diff) <= closest_target || closest_target == 0)
		{
			ctfrom_index = index;
			if (diff > 0)
				ctfrom_index++;
			closest_target = abs(diff);
		}
		index++;
		i = i->next;
	}
	return (ctfrom_index);
}
