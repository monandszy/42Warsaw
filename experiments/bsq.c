
/*
Allowed functions and globals: 

malloc, calloc, realloc, free, 

fopen, fclose,
getline, fscanf, fputs, fprintf

estderr, stdout, stdin, errno
*/

#include <stdio.h>
#include <stdlib.h>

int error() {
  printf("map error");
  return (1);
}


typedef struct s_data {
  int linec;
  char empty;
  char obstacle;
  char full;
} t_data;


int validate_char(char *line, char *c, int *i) {
  if (!line[*i] || line[*i] != ' ')
    return (1);
  (*i)++;
  if (!line[*i])
    return (1);
  *c = line[*i];
  (*i)++;
  return 0;
}

int validate(char *line, t_data *d) {
  int i = 0;
  while(line[i] && line[i] <= '9' && line[i] >= '0') {
    d->linec *= 10;
    d->linec += (line[i] - '0');
    i++;
  }
  if (i == 0)
    return (error());
  if (validate_char(line, &d->empty, &i))
    return (error());
  if (validate_char(line, &d->obstacle, &i))
    return (error());
  if (validate_char(line, &d->full, &i))
    return (error());
  return (0);
}

int initialize(char **map, FILE *f, t_data *d) {
  char *line = NULL;
  size_t len = 0;
  size_t prev_len = 0;
  long read;

  read = getline(&line, &prev_len, f);
  map[0] = line;
  int i = 1;
  while (read > 0) {
    read = getline(&line, &len, f);
    if (len != prev_len)
      return (error()); 
    map[i] = line;
    if (i > d->linec)
      return (error());  
    i++;
  } 
  if (i - 1 != d->linec)
    return (error());
  return (0);
}

int main(int argc, char **argv) {
  static t_data d;
  if (argc == 2) {
    FILE *f = fopen(argv[1], "r+");
    char *line = NULL;
    size_t len = 0;
    long read = getline(&line, &len, f);

    if (validate(line, &d))
      return 1;
    // printf("%d, %c, %c, %c\n", d.linec, d.empty, d.obstacle, d.full);

    char **map = (char **) malloc (sizeof(char *) * d.linec + 1);
    map[d.linec] = NULL;

    if (initialize(map, f, &d))
      return 1;

    int i = 0;
    while(map[i]) {
      printf("%s\n", map[i]);
      i++;
    }
  }
}