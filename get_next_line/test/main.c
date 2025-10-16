
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
	buf = get_next_line(fd);
	printf("{%d}", printf("[%s]", buf));
	free (buf);
	close(fd);
	return (0);
}
