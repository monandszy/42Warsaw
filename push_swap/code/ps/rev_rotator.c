#include "ps.h"

static void rrotate(t_stack *s)
{
  t_dlist *start;
  t_dlist *end;
  t_dlist *second_last;

  start = s -> start;
  end = s -> end;
  second_last = end -> prev;

  second_last -> next = NULL;
  s -> end = second_last;
  end -> prev = NULL;
  start -> prev = end;
  end -> next = start;
  s -> start = end;
}

t_list *rra(t_list *steps, t_stack *a)
{
  rrotate(a);
  steps -> next = ft_lstnew("rra");
  return (steps -> next);
}

t_list *rrb(t_list *steps, t_stack *b)
{
  rrotate(b);
  steps -> next = ft_lstnew("rrb");
  return (steps -> next);
}

t_list *rrr(t_list *steps, t_stack *a, t_stack *b)
{
  rrotate(a);
  rrotate(b);
  steps -> next = ft_lstnew("rrr");
  return (steps -> next);
}