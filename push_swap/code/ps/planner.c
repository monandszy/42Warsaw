
#include "ps.h"

int	plan(t_dlist **steps, t_stack *a, t_stack *b)
{
  t_dlist *start;

  if (a -> e_count <= 1)
    return (0);
  *steps = ft_dlstnew(ft_strdup("INIT"));
  start = *steps;
  if (!*steps)
    return (1);
  print_stack(a);
  print_stack(b);
  while (a -> e_count > 0)
  {
    // printf("\n");
    execute_optimal_move(steps, a, b);
    print_dlist(&start);
    print_stack(a);
    print_stack(b);
    // printf("\n");
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
  size_t cs;
  size_t ce;
  t_dlist *i;

  i = b -> start;
  cs = 0;
  ce = 0;
  while (cs <= (b -> e_count / 2) && *((int*) (i -> content)) < *((int*) (i -> next -> content)))
  {
    cs++;
    i = i -> next;
  }
  i = b -> end;
  while (ce <= (b -> e_count / 2) && *((int*) (i -> content)) < *((int*) (i -> prev -> content)))
  {
    ce++;
    i = i -> prev;
  }
  if (cs > ce)
    while (*((int*) (b -> start -> content)) < *((int*) (b -> end -> content)))
      *steps = rb(*steps, b);
  else
    while (*((int*) (b -> start -> content)) < *((int*) (b -> end -> content)))
      *steps = rrb(*steps, b);
}

