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

int process_object(t_parser_data *pd, char *obj, t_entry *entry)
{
  char **parts;
  char *specifier;

  parts = ft_split(obj, ' ');
  if (!parts || !parts[0])
    return (error(pd, "Error: Split failed or empty object\n"));

  pd->parts = parts;
  specifier = parts[0];
  if (ft_strncmp(specifier, "A", 2))
    process_Ambient(pd, parts, entry);
  else if (ft_strncmp(specifier, "C", 2))
    process_Camera(pd, parts, entry);
  else if (ft_strncmp(specifier, "L", 2))
    process_Light(pd, parts, entry);
  else if (ft_strncmp(specifier, "sp", 3))
    process_sphere(pd, parts, entry);
  else if (ft_strncmp(specifier, "pl", 3))
    process_plane(pd, parts, entry);
  else if (ft_strncmp(specifier, "cy", 3))
    process_cylinder(pd, parts, entry);
  free_split(parts);
  pd->parts = NULL;
  return (0);
}

int parse_file(t_data *d, char *file)
{
  static t_parser_data pd;
  char **objects;
  t_entry *entries;
  size_t len;
  size_t i;

  pd.file_content = file;
  objects = ft_split(file, '\n');
  if (!objects)
    return (error(&pd, "Error: Split objects failed\n"));
  pd.objects = objects;

  len = split_len(objects);
  entries = (t_entry *) malloc(sizeof(t_entry) * len);
  if (!entries)
    return (error(&pd, "Error: Malloc entries failed\n"));
  ft_bzero(entries, sizeof(t_entry) * len);
  pd.entries = entries;

  i = 0;
  while(i < len)
  {
    if (process_object(&pd, objects[i], &entries[i]))
      return (error(&pd, "Error: Process object failed\n"));
    i++;
  }
  free_split(objects);
  d->objects = entries;
  return (0);
}
