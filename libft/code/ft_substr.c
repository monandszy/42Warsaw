#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int i;
	size_t olen;
	char *substr;

	olen = ft_strlen(s);

	len = olen - start;
	if (len <= 0)
		return (malloc(0));
	
	i = 0;
	substr = (char *) malloc (len + 1);
	if (substr == NULL)
		return (NULL);
	substr[len + 1] = '\0';
	ft_memcpy(substr, &s[start], len);
	return (substr);
}
