/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   planner.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 13:04:16 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/10 16:57:24 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

int    push_chunks(t_dlist **steps, t_stack *a, t_stack *b);
int    push_back(t_dlist **steps, t_stack *a, t_stack *b);

int	plan(int *schema, t_dlist **steps, t_stack *a, t_stack *b)
{
	t_dlist	*start;

	*steps = ft_dlstnew(ft_strdup("INIT"));
	start = *steps;
	if (!*steps)
		return (1);
  // push_chunks(steps, a, b);
  // if (transfer(steps, a, b))
    // return (1);

	execute_lis(schema, steps, a, b);
  // push_back(steps, a, b);
	while ((int) b->e_count > 0)
	  if (execute_optimal_move(steps, a, b))
      return (1);
	if (adjust_order(steps, a))
    return (1);
	*steps = start;
	return (0);
}

int	transfer(t_dlist **steps, t_stack *a, t_stack *b)
{
	while ((int) a->e_count > 0)
  {
		*steps = pb(*steps, a, b);
    if (!*steps)
      return (1);
  }
	return (0);
}
