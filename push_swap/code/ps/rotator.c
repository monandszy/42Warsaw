#include "ps.h"

static void	rotate(t_stack *s)
{
	t_dlist	*start;
	t_dlist	*second;
	t_dlist	*end;

	start = s->start;
	end = s->end;
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
	rotate(a);
	steps->next = ft_dlstnew("ra");
	return (steps->next);
}

t_dlist	*rb(t_dlist *steps, t_stack *b)
{
	rotate(b);
	steps->next = ft_dlstnew("rb");
	return (steps->next);
}

t_dlist	*rr(t_dlist *steps, t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	steps->next = ft_dlstnew("rr");
	return (steps->next);
}
