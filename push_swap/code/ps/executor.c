
#include "ps.h"

void execute_optimal_move(t_dlist **steps, t_stack *a, t_stack *b)
{
  t_move *move;

  move = calculate_optimal_rr_cost(a, b);
  print_move(move);
  execute_optimal_rr_move(steps, a, b, move);
  free(move);
}

void execute_optimal_rr_move(t_dlist **steps, t_stack *a, t_stack *b, t_move *move)
{
  while(move -> shared > 0)
  {
    *steps = rr(*steps, a, b);
    move -> shared--;
  }
  while (move -> b_index > 0)
  {
    *steps = rb(*steps, b);
    move -> b_index--;
  }
  while (move -> a_index > 0)
  {
    *steps = ra(*steps, a);
    move -> a_index--;
  }
  *steps = pb(*steps, a, b);
}