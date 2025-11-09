#include "ps.h"

void	rotate(t_stack *s)
{
	t_dlist	*start;
	t_dlist	*second;
	t_dlist	*end;

	start = s->start;
	end = s->end;
	if (start == end)
		return ;
	second = start->next;
	second->prev = NULL;
	s->start = second;
	start->next = NULL;
	start->prev = end;
	end->next = start;
	s->end = start;
}

t_dlist	*ra(t_dlist *steps, t_stack *a)
{
	if (a->e_count <= 1)
		return (steps);
	rotate(a);
	steps->next = ft_dlstnew(ft_strdup("ra"));
	steps->next->prev = steps;
	return (steps->next);
}

t_dlist	*rb(t_dlist *steps, t_stack *b)
{
	if (b->e_count <= 1)
		return (steps);
	rotate(b);
	steps->next = ft_dlstnew(ft_strdup("rb"));
	steps->next->prev = steps;
	return (steps->next);
}

t_dlist	*rr(t_dlist *steps, t_stack *a, t_stack *b)
{
	if (a->e_count <= 1 && b->e_count <= 1)
		return (steps);
	rotate(a);
	rotate(b);
	steps->next = ft_dlstnew(ft_strdup("rr"));
	steps->next->prev = steps;
	return (steps->next);
}
