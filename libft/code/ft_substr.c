
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int i;
	char *substr;

	if (ft_strlen(s) - 1 > start)
		return (NULL);

	i = 0;
	substr = (char *) malloc (len);
	while (i < len && s[start])
	{
		substr[i] = s[start]
		start++;
	}
	substr[i] = '\0';

	return (substr);
}
