#include <stdio.h>

int main(void) {
  char *line = NULL;
  size_t len = 0;
  getline(&line, &len, stdin);
  fprintf(stdout, "%s", line);
}