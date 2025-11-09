
#include "ps.h"

int	plan(int *schema, t_dlist **steps, t_stack *a, t_stack *b)
{
  t_dlist *start;
  int cost;

  if (a -> e_count <= 1)
    return (0);
  *steps = ft_dlstnew(ft_strdup("INIT"));
  start = *steps;
  if (!*steps)
    return (1);
  // print_stack(a);
  // print_stack(b);
  // cost = transfer(steps, a, b);
  cost = execute_lis(schema, steps, a, b);
  free(schema);
  if (find_solution_recursive(steps, a, b, cost) == 1)
  {
    // while (b -> e_count > 0)
    // {
    //   cost += execute_optimal_move(steps, a, b);
    // }
    // adjust_order_move(steps, a, 0);
  }
  // print_stack(a);
  // print_stack(b);
  *steps = start;
	return (0);
}

int transfer(t_dlist **steps, t_stack *a, t_stack *b)
{
  int cost;

  cost = a -> e_count;
  while(a -> e_count > 0)
    *steps = pb(*steps, a, b);
  return (cost);
}


