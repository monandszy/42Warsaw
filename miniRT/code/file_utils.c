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

void process_object(char *obj, t_entry *entry)
{
  char **parts;
  char *specifier;
  size_t len;

  parts = ft_split(obj, ' ');
  if (!parts || !*parts)
    return ;
  len = split_len(parts);

  specifier = parts[0];
  if (ft_strncmp(specifier, "A", 2))
    process_Ambient(parts, entry, len);
  else if (ft_strncmp(specifier, "C", 2))
    process_Camera(parts, entry, len);
  else if (ft_strncmp(specifier, "L", 2))
    process_Light(parts, entry, len);
  else if (ft_strncmp(specifier, "sp", 3))
    process_sphere(parts, entry, len);
  else if (ft_strncmp(specifier, "pl", 3))
    process_plane(parts, entry, len);
  else if (ft_strncmp(specifier, "cy", 3))
    process_cylinder(parts, entry, len);
  free_split(parts);
}

int parse_file(t_data *d, char *file)
{
  char **objects;
  t_entry *entries;
  size_t len;
  size_t i;

  objects = ft_split(file, '\n');
  if (!objects)
    return (1);
    
  len = split_len(objects);
  entries = (t_entry *) malloc(sizeof(t_entry) * len);
  if (!entries)
    return (free_split(objects), 1);

  i = 0;
  while(i < len)
  {
    process_object(objects[i], &entries[i]);
    i++;
  }
  free_split(objects);
  d->objects = entries;
  return (0);
}
