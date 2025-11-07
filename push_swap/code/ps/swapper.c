#include "ps.h"

void	swap(t_stack *s)
{
	t_dlist	*start;
	t_dlist	*second;
	void	*tmp;

	start = s->start;
	second = start->next;
	if (!second)
		return ;
	tmp = start->content;
	start->content = second->content;
	second->content = tmp;
}

void swap_first(t_stack *a, t_stack *b)
{
  t_dlist *a_start;
	t_dlist *b_start;
	void *tmp;

	a_start = a->start;
	b_start = b->start;
	if (!a_start || !b_start)
		return ;
	tmp = a_start->content;
	a_start->content = b_start->content;
	b_start->content = tmp;
}

t_dlist	*sa(t_dlist *steps, t_stack *a)
{
	swap(a);
	steps->next = ft_dlstnew(ft_strdup("sa"));
  steps->next->prev = steps;
	return (steps->next);
}

t_dlist	*sb(t_dlist *steps, t_stack *b)
{
	swap(b);
  steps->next->prev = steps;
	steps->next = ft_dlstnew(ft_strdup("sb"));
	return (steps->next);
}

t_dlist	*ss(t_dlist *steps, t_stack *a, t_stack *b)
{
  swap_first(a, b);
  steps->next->prev = steps;
	steps->next = ft_dlstnew(ft_strdup("ss"));
	return (steps->next);
}