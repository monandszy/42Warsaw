
#include "libft.h"

char *recursive(int n, int iter)
{
	int i;
	char *out;

	if (n > 0)
	{
		i = n % 10;
		iter++;
		out = recursive(n/10, iter);
		if (out == NULL)
			return (NULL);
		out[iter] = (i + '0');
		return (out);
	}
	iter++;
	out = (char *) malloc(iter * sizeof(char));
	if (out == NULL)
		return (NULL);
	out[iter] = '\0';
	return (out);

}

char *ft_itoa(int n)
{
	char *str;

	if (n < 0)
	{
		str = recursive(-n, 1);
		str[0] = '-';
		return (str);
	}
	else
		return (recursive(n, 0));
}
