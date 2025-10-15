#include <stdio.h>
#include <stdlib.h>

void	test2(char **test)
{
	test[0] = "hi";
}

int	main(void)
{
	char **test;
	test = malloc(sizeof(char *));
	*test = "hello";
	test2(test);
	printf("%s", test[0]);
	return (0);
}
