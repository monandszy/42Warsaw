#include "ps.h"

void	swap(t_stack *s)
{
	t_dlist	*start;
	t_dlist	*second;

	start = s->start;
	if (!start)
		return ;
	second = start->next;
	if (!second)
		return ;
	if (second->next)
		second->next->prev = start;
	if (s->end == second)
		s->end = start;
	s->start = second;
	start->prev = second;
	start->next = second->next;
	second->prev = NULL;
	second->next = start;
}

void	swap_top(t_stack *a, t_stack *b)
{
	if (!a->start || !b->start)
	{
		if (!a->start)
			push(a, b);
		else if (!b->start)
			push(b, a);
		return ;
	}
	push(a, b);
	swap(a);
	push(b, a);
}

t_dlist	*sa(t_dlist *steps, t_stack *a)
{
	if (a->e_count < 2)
		return (steps);
	swap(a);
	steps->next = ft_dlstnew(ft_strdup("sa"));
	steps->next->prev = steps;
	return (steps->next);
}

t_dlist	*sb(t_dlist *steps, t_stack *b)
{
	if (b->e_count < 2)
		return (steps);
	swap(b);
	steps->next->prev = steps;
	steps->next = ft_dlstnew(ft_strdup("sb"));
	return (steps->next);
}

t_dlist	*ss(t_dlist *steps, t_stack *a, t_stack *b)
{
	if (a->e_count == 0 && b->e_count == 0)
		return (steps);
	swap_top(a, b);
	steps->next->prev = steps;
	steps->next = ft_dlstnew(ft_strdup("ss"));
	return (steps->next);
}