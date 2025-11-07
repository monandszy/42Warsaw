
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
    b_index = calculate_rb_move(*((int *) (i -> content)), b);
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

int calculate_rb_move(int target, t_stack *b)
{
  t_dlist *i;
  int closest_target;
  int diff;
  int ctb_index;
  int b_index;

  b_index = 0;
  closest_target = 0;
  ctb_index = 0;
  i = b -> start;
  while (i)
  {
    // diff = ft_abs(target - (i -> target));
    diff = target - *((int*) (i -> content));
    // printf("diff:[%d] ct:[%d]\n", diff, closest_target);
    // if element in b > than element of a
    // means that a is to be on top of b
    if (ft_abs(diff) <= closest_target || closest_target == 0)
    {
      ctb_index = b_index;
      if (diff < 0)
        ctb_index++;
      closest_target = ft_abs(diff);
    }
    b_index++;
    i = i -> next;
  }
  return (ctb_index);
}