
#include "ps.h"

// move from b to a
int execute_optimal_move(t_dlist **steps, t_stack *a, t_stack *b)
{
  t_move *rr_move;
  t_move *rrr_move;

  rr_move = calculate_optimal_rr_cost(b, a);
  rrr_move = calculate_optimal_rrr_cost(b, a);
  if (!rr_move || !rrr_move)
    return (free(rr_move), free(rrr_move), 1);
  print_move(rrr_move);
  print_move(rr_move);
  if (rrr_move -> cost > rr_move->cost)
  {
    if (execute_optimal_rr_move(steps, a, b, rr_move))
      return (free(rr_move), free(rrr_move), 1);
  }
  else
  {
    if (execute_optimal_rrr_move(steps, a, b, rrr_move))
      return (free(rr_move), free(rrr_move), 1);
  }
  return (free(rr_move), free(rrr_move), 0);
}

int execute_optimal_rr_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
  while (move -> shared > 0)
  {
    *steps = rr(*steps, a, b);
    move -> shared--;
  }
  while (move -> from_index > 0)
  {
    *steps = rb(*steps, b);
    move -> from_index--;
  }
  while (move -> to_index > 0)
  {
    *steps = ra(*steps, a);
    move -> to_index--;
  }
  *steps = pa(*steps, a, b);
  return (0);
}

int execute_optimal_rrr_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
  while (move -> shared > 0)
  {
    *steps = rrr(*steps, a, b);
    move -> shared--;
  }
  while (move -> from_index > 0)
  {
    *steps = rrb(*steps, b);
    move -> from_index--;
  }
  while (move -> to_index > 0)
  {
    *steps = rra(*steps, a);
    move -> to_index--;
  }
  *steps = pa(*steps, a, b);
  return (0);
}