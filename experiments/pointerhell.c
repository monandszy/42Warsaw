#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>

int main(void)
{
	char *s1;
	char **p2;

	s1 = (char *) malloc(sizeof(char) * 11);

	char *t = "howisthispossible";
	for(int i = 0; i < 10; i ++)
	{
		s1[i] = t[i];
	}
	s1[10] = '\0';

	p2 = &s1;

	printf("[%s]\n", s1);

	s1++;
	printf("[%s]\n", s1);
//	p2++;
//	printf("[%s]\n", s1);
	(*p2)++;
	printf("[%s]\n", s1);
	s1 += 1;
	printf("[%s]\n", s1);

	*s1 += 1;
	printf("[%s]\n", s1);

	**p2 += 1;
	printf("[%s]\n", s1);
}
