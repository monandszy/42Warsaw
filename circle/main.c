
#include <stdio.h>
int main(void)
{
	char *str = "/=∂/\\/\\[](_)§ /\\/\\@|V †|-|@¯|¯ /-/!570®1<|-\\£1_`/ ¢@/\\/\\ε vv!7}{ ???";
	int i;

	while(str[i])
	{
		printf("[%c: %d]\n", str[i], (int) str[i]);
		i++;
	}
}
