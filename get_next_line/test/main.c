
#include "test.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "./../code/get_next_line.h"
#include <string.h>

void test(char *path)
{
	int fd = open(path, O_RDONLY);
	FILE *fp = fopen(path, "r");

	char *s1;
	char *s2;
	int i = 0;
	while(i < 20)
	{
		s1 = better_get_next_line(fp);
		s2 = get_next_line(fd);
		if (s1 != NULL && s2 != NULL)
		{
			if (strncmp(s1, s2, ft_strlen(s1)))
			{
				printf("[Error while reading \"%s\"]\n", path);
				printf("[Expected: \"%s\" Got: \"%s\"]\n", s1, s2);
			}
		}
		else if ((s1 == NULL && s2 != NULL) ||(s1 != NULL && s2 == NULL))
		{
				printf("[Error while reading \"%s\"]\n", path);
				printf("[Expected: \"%s\" Got: \"%s\"]\n", s1, s2);
		}
		free (s1);
		free (s2);
		i++;
	}
	close(fd);
	fclose(fp);
}

int main(void)
{
	test("./testdir/empty");
	test("./testdir/random");
	test("./testdir/long");
	test("./testdir/test_file");
	return (0);
}
