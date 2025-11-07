#include "ps.h"

void	rrotate(t_stack *s)
{
	t_dlist	*start;
	t_dlist	*end;
	t_dlist	*second_last;

	start = s->start;
	end = s->end;
  if (start == end)
    return ;
	second_last = end->prev;
	second_last->next = NULL;
	s->end = second_last;
	end->prev = NULL;
	start->prev = end;
	end->next = start;
	s->start = end;
}

t_dlist	*rra(t_dlist *steps, t_stack *a)
{
  if (a -> e_count <= 1)
    return (steps);
	rrotate(a);
	steps->next = ft_dlstnew(ft_strdup("rra"));
  steps->next->prev = steps;
	return (steps->next);
}

t_dlist	*rrb(t_dlist *steps, t_stack *b)
{
  if (b -> e_count <= 1)
    return (steps);
	rrotate(b);
	steps->next = ft_dlstnew(ft_strdup("rrb"));
  steps->next->prev = steps;
	return (steps->next);
}

t_dlist	*rrr(t_dlist *steps, t_stack *a, t_stack *b)
{
  if (a -> e_count <= 1 && b -> e_count <= 1)
    return (steps);
	rrotate(a);
	rrotate(b);
	steps->next = ft_dlstnew(ft_strdup("rrr"));
  steps->next->prev = steps;
	return (steps->next);
}