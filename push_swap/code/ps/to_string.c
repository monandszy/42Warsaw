
#include "ps.h"

void print_move(t_move *move)
{
  printf("move:[shared: %d, b_i: %d, a_i: %d, cost: %d]\n", 
  move -> shared,
  move -> b_index,
  move -> a_index,
  move -> cost);
  fflush(stdout);
}

void print_stack(t_stack *stack)
{
  t_dlist *i;

  printf("%s", "stack:[");
  i = stack -> start;
  while (i)
  {
    printf("(%d)", *((int *)(i -> content)));
    i = i -> next;
  }
  printf("%s", "]\n");
  fflush(stdout);
}

void print_dlist(t_dlist **dl)
{
  t_dlist *i;

  printf("%s", "dlist:[");
  i = *dl;
  while (i)
  {
    printf("(%s)", ((char *)(i -> content)));
    i = i -> next;
  }
  printf("%s", "]\n");
  fflush(stdout);
}

// void print_move(t_move *move)
// {
//   (void) move;
// }

// void print_stack(t_stack *stack)
// {
//   (void) stack;
// }
// void print_dlist(t_dlist **dl)
// {
//   (void) dl;
// }

