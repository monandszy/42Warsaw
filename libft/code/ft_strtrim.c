
#include "libft.h"

static int is_in_set(char c, char const *set);

char *ft_strtrim(char const *s1, char const *set)
{
	unsigned int i;
	unsigned int j;
	size_t len;
	char *new;

	i = 0;
	j = 0;
	len = ft_strlen(s1);
	while (is_in_set(s1[i], set) && s1[i])	
		i++;
	if (i == len)
		return(malloc(0));
	while (is_in_set(s1[len + j], set) && s1[j])
		j++;
	len = len - i - j;
	new = (char *) malloc((len + 1) * sizeof(char));
	new[len + 1] = '\0';
	if (new == NULL)
		return (NULL);
	return (ft_memcpy(new, &s1[i], len));
}

int is_in_set(char c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}
