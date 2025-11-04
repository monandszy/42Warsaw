#include "ps.h"

// pushes from b to a
static void push(t_stack *to, t_stack *from)
{
  t_dlist *from_start;
  t_dlist *to_start;

  to_start = to -> start;
  from_start = from -> start;

  if (!from_start)
    return;
  from -> size--;
  to -> size++;
  from -> start = from_start -> next;
  from_start -> prev = NULL;
  from_start -> next = to_start;
  to_start -> prev = from_start;
  to -> start = from_start;
}

t_list *pa(t_list *steps, t_stack *a, t_stack *b)
{
  push(a, b);
  steps -> next = ft_lstnew("pa");
  return (steps -> next);
}

t_list *pb(t_list *steps, t_stack *a, t_stack *b)
{
  push(b, a);
  steps -> next = ft_lstnew("pb");
  return (steps -> next);
}