
#include "libft.h"

void ft_lstclear(t_list **lst, void(*del)(void *))
{
	t_list *tmp;
	t_list *i;

	if (lst == NULL || del == NULL)
		return ;
	else if (*lst == NULL)
	{
		*lst = NULL;
		return ;
	}
	i = *lst;
	while (i != NULL)
	{
		(*del)(i -> content);
		tmp = i;
		i = tmp -> next;
		free(tmp);
	}
	*lst = NULL;
}
