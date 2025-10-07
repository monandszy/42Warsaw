
#include "libft.h"

static void fdel(void *p)
{
	free(p);
}

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *i;
	t_list *prev;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	prev = ft_lstnew((*f)(lst -> content));
	if (prev == NULL)
		return (NULL);
	lst = lst -> next;
	new = prev;
	while (lst != NULL)
	{
		i = ft_lstnew((*f)(lst -> content));
		if (i == NULL)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst -> next;
		prev -> next = i;
		prev = prev -> next;
	}
	ft_lstclear(&lst, &fdel);
	return (new);
}
