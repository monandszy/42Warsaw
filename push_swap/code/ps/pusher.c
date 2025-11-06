#include "ps.h"

// pushes from b to a
static void	push(t_stack *to, t_stack *from)
{
	t_dlist	*from_start;
	t_dlist	*to_start;

	to_start = to->start;
	from_start = from->start;
	if (!from_start)
		return ;
	from->e_count--;
	to->e_count++;
	from->start = from_start->next;
	from_start->prev = NULL;
	from_start->next = to_start;
  if (to_start)
	  to_start->prev = from_start;
  if (!to -> end)
    to -> end = from_start;
	to->start = from_start;
}

t_dlist	*pa(t_dlist *steps, t_stack *a, t_stack *b)
{
	push(a, b);
	steps->next = ft_dlstnew(ft_strdup("pa"));
  steps->next->prev = steps;
	return (steps->next);
}

t_dlist	*pb(t_dlist *steps, t_stack *a, t_stack *b)
{
	push(b, a);
	steps->next = ft_dlstnew(ft_strdup("pb"));
  steps->next->prev = steps;
	return (steps->next);
}