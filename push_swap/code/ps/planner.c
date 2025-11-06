
#include "ps.h"

int	plan(t_dlist **steps, t_stack *a, t_stack *b)
{
  *steps = ft_dlstnew(ft_strdup("INIT"));
  t_dlist *start;
  
  start = *steps;
  // (void) a;
  // (void) b;
  // t_dlist *i;

  // if (!steps)
  //   return (1);
  if (a -> e_count <= 1)
    return (0);

  // i = a -> start;
  // size = a -> e_count;
  print_stack(a);
  print_stack(b);
  while (a -> e_count > 0)
  {
    // printf("\n");
    // print_stack(a);
    // print_stack(b);
    execute_optimal_move(steps, a, b);
    print_dlist(&start);
    print_stack(a);
    print_stack(b);
    // printf("\n");
  }
  *steps = start;
	return (0);
}

