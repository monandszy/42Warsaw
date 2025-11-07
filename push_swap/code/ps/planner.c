
#include "ps.h"

int	plan(t_dlist **steps, t_stack *a, t_stack *b)
{
  t_dlist *start;

  *steps = ft_dlstnew(ft_strdup("INIT"));
  if (!steps)
    return (1);
  start = *steps;

  if (a -> e_count <= 1)
    return (0);
  // *steps = pb(*steps, a, b);
  // *steps = pb(*steps, a, b);
  print_stack(a);
  print_stack(b);
  while (a -> e_count > 0)
  {
    printf("\n");
    print_stack(a);
    print_stack(b);
    execute_optimal_move(steps, a, b);
    print_dlist(&start);
    print_stack(a);
    print_stack(b);
    printf("\n");
  }
  adjust_order(steps, b);
  transfer(*steps, a, b);
  print_stack(a);
  print_stack(b);
  *steps = start;
	return (0);
}

// TODO make it intelligent to start from back or start;
void adjust_order(t_dlist **steps, t_stack *b)
{
  while (*((int*) (b -> start -> content)) < *((int*) (b -> end -> content)))
  {
    *steps = rb(*steps, b);
  }
}

