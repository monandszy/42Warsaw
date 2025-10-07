
#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
	unsigned int i;

	if (lst == NULL)
		return (NULL);
	i = 0;
	while (lst -> next != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (lst);
}
