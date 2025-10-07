
#include "libft.h"

void ft_lstclear(t_list **lst, void(*del)(void *))
{
	t_list *tmp;
	t_list *current;

	if (lst == NULL || del == NULL)
		return ;
	else if (*lst == NULL)
	{
		lst = NULL;
		return ;
	}
	current = *lst;
	tmp = current -> next;
	while (tmp != NULL)
	{
		(*del)(current -> content);
		free(current);
		*lst = tmp;
		current = *lst;
		tmp = current -> next;
	}
	lst = NULL;
}
