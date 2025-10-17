
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "./../code/get_next_line.h"

int main(void)
{
	char *buf;
	char *fn = "./test_file";
	int fd = open(fn, O_RDONLY);
	int i = 0;
	while (i <= 20)
	{
		buf = get_next_line(fd);
		int c = 
		printf("[%s]", buf);
		free (buf);
		printf("{%d}", c);
		i++;
	}
	return (0);
}
