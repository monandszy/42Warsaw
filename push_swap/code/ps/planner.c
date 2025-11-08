
#include "ps.h"

int	plan(int *schema, t_dlist **steps, t_stack *a, t_stack *b)
{
  t_dlist *start;

  if (a -> e_count <= 1)
    return (0);
  *steps = ft_dlstnew(ft_strdup("INIT"));
  start = *steps;
  if (!*steps)
    return (1);
  *steps = execute_lis(schema, *steps, a, b);
  free(schema);
  while (b -> e_count > 0)
    execute_optimal_move(steps, a, b);
  adjust_order(steps, a);
  *steps = start;
	return (0);
}

void adjust_order(t_dlist **steps, t_stack *a)
{
  size_t cs;
  size_t ce;
  t_dlist *i;

  i = a -> start;
  cs = 0;
  ce = 0;
  while (cs <= (a -> e_count / 2) && *((int*) (i -> content)) > *((int*) (i -> next -> content)))
  {
    cs++;
    i = i -> next;
  }
  i = a -> end;
  while (ce <= (a -> e_count / 2) && *((int*) (i -> content)) > *((int*) (i -> prev -> content)))
  {
    ce++;
    i = i -> prev;
  }
  if (cs > ce)
    while (*((int*) (a -> start -> content)) > *((int*) (a -> end -> content)))
      *steps = ra(*steps, a);
  else
    while (*((int*) (a -> start -> content)) > *((int*) (a -> end -> content)))
      *steps = rra(*steps, a);
}

