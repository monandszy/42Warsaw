
#include "ps.h"

t_move *calculate_optimal_rr_cost(t_stack *a, t_stack *b)
{
  int a_index;
  int b_index;
  t_dlist *i;

  t_move *min_cost;
  t_move *cost;

  min_cost = NULL;
  i = a -> start;
  a_index = 0;
  while (i 
  // && a_index <= (a -> e_count / 2)
  )
  {
    b_index = calculate_b_move_rr(*((int *) (i -> content)), b);
    cost = calculate_cost(a_index, b_index);
    if (!min_cost || cost->cost < min_cost->cost)
    {
      free(min_cost);
      min_cost = cost;
    }
    else
      free(cost);
    a_index++;
    i = i -> next;
  }
  return (min_cost);
}

int calculate_b_move_rr(int target, t_stack *b)
{
  t_dlist *i;
  int closest_target;
  int diff;
  int ctb_index;
  int b_index;

  b_index = 0;
  ctb_index = 0;
  i = b -> start;
  while (i)
  {
    // diff = ft_abs(target - (i -> target));
    diff = ft_abs(target - *((int*) (i -> content)));
    // printf("diff:[%d]\n", diff);
    // if element in b > than element of a
    // means that a is to be on top of b
    if (diff < closest_target)
    {
      ctb_index = b_index;
      closest_target = diff;
    }
    b_index++;
    i = i -> next;
  }
  return (ctb_index);
}