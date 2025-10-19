#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

char *better_get_next_line(FILE *fp) {
    char * line = NULL;
    size_t len = 0;
	long read;
    read = getline(&line, &len, fp);
	if (read <= 0)
	{
		free(line);
		return (NULL);
	}
    return (line);
}
