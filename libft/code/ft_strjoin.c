
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
	size_t l1;
	size_t l2;
	char *new;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);

	if (s1 == 0 && s2 == 0)
		return malloc(0);
	new = (char *) malloc((l1 + l2 + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	new[l1 + l2 + 1] = '\0';

	ft_memcpy(new, s1, l1);
	ft_memcpy(&new[l1 + 1], s2, l2);
	return (new);
}
