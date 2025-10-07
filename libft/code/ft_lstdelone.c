
#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
	       return ;
	else if (del == NULL)
		free(lst);
	else
	{	
		(*del)(lst -> content);
		free(lst);
	}
}
// how does the previous node handle the removal?
