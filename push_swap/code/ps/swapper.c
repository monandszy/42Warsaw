#include "ps.h"

static void swap(t_list, t_stack *s)
{
  t_dlist *start;
  t_dlist *second;
  int tmp;

  start = s -> start;
  second = start -> next;
  if (!second)
    return;
  tmp = start -> content;
  start -> content = second -> content;
  second -> content = tmp;
}

t_list *sa(t_list *steps, t_stack *a)
{
  swap(steps, a);
  steps -> next = ft_lstnew("sa");
  return (steps -> next);
}

t_list *sb(t_list *steps, t_stack *b)
{
  swap(steps, b);
  steps -> next = ft_lstnew("sb");
  return (steps -> next);
}

t_list *ss(t_list *steps, t_stack *a, t_stack *b)
{
  t_dlist *a_start;
  t_dlist *b_start;
  int tmp;

  a_start = a -> start;
  b_start = b -> start;
  if (!a_start || !b_start)
    return;
  tmp = a_start -> content;
  a_start -> content = b_start -> content;
  b_start -> content = tmp;
  steps -> next = ft_lstnew("ss");
  return (steps -> next);
}