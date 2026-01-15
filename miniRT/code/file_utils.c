#include "miniRT.h"

char	*read_all(t_data *d, int fd)
{
	int		bread;
	char	buffer[101];
	char	*content;
	char	*tmp;

	if (fd < 0)
		end(d);
	bread = 1;
	content = NULL;
	while (bread > 0)
	{
		bread = read(fd, buffer, 100);
		buffer[bread] = '\0';
		tmp = content;
		content = ft_strjoin(content, buffer);
		if (!content)
			end(d);
		free(tmp);
	}
	return (content);
}

void remove_sqnl(char *file)
{
  int i;

  i = 0;
  while(file[i])
  {
    if (file[i] == '\n' && file[i+1] == '\n')
      file[i] = ' ';
    i++;
  }
}

char *initialize_file(t_data *d, char *name)
{
  int fd;
  char *file;

  (void) d;
  fd = open(name, O_RDONLY);
  if (fd < 0)
    return(perror(name), NULL);
  file = read_all(d, fd);
  if (!file)
    return (NULL);
  remove_sqnl(file);
  return (file);
}
