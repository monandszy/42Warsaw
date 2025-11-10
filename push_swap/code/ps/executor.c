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

int		find_origin(t_stack *a);

int	adjust_order(t_dlist **steps, t_stack *a)
{
  int target;
  
  target = find_origin(a);
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

int find_origin(t_stack *stack)
{
    t_dlist *i;
    int index;

    i = stack->start;
    index = 0;
    while (i)
    {
        if ( *(int *) i->content == 0)
            return (index);
        i = i->next;
        index++;
    }
    return (-1);
}

int	execute_optimal_move(t_dlist **steps, t_stack *a, t_stack *b)
{
	t_move	*rr_move;
	t_move	*rrr_move;

	rr_move = calculate_optimal_rr_cost(b, a);
	rrr_move = calculate_optimal_rrr_cost(b, a);
	if (!rr_move || !rrr_move)
		return (free(rr_move), free(rrr_move), 1);
	if (rrr_move->cost > rr_move->cost)
	{
		if (execute_move(steps, a, b, rr_move))
			return (free(rr_move), free(rrr_move), 1);
	}
	else
	{
		if (execute_move(steps, a, b, rrr_move))
			return (free(rr_move), free(rrr_move), 1);
	}
	return (free(rr_move), free(rrr_move), 0);
}
