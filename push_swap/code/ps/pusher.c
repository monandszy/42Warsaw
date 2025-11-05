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
	from->size--;
	to->size++;
	from->start = from_start->next;
	from_start->prev = NULL;
	from_start->next = to_start;
	to_start->prev = from_start;
	to->start = from_start;
}

t_dlist	*pa(t_dlist *steps, t_stack *a, t_stack *b)
{
	push(a, b);
	steps->next = ft_dlstnew("pa");
	return (steps->next);
}

t_dlist	*pb(t_dlist *steps, t_stack *a, t_stack *b)
{
	push(b, a);
	steps->next = ft_dlstnew("pb");
	return (steps->next);
}