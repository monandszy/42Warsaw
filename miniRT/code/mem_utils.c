#include "miniRT.h"

void	free_split(char **sp)
{
	int	i;

	i = 0;
	if (sp)
	{
		while (sp[i])
		{
			free(sp[i]);
			i++;
		}
		free(sp);
	}
}

void free_entries(t_entry *entries, size_t len)
{
	size_t	i;

	if (!entries)
		return ;
	i = 0;
	while (i < len)
	{
		if (entries[i].obj)
			free(entries[i].obj);
		i++;
	}
	free(entries);
}

int error(t_parser_data *pd, char *msg)
{
  size_t len;

  print_error(msg);
  fflush(stdout);
  if (pd->parts)
    free_split(pd->parts);
  if (pd->objects)
  {
    len = split_len(pd->objects);
    if (pd->entries)
      free_entries(pd->entries, len);
    free_split(pd->objects);
  }
  else if (pd->entries)
    free(pd->entries);
  if (pd->file_content)
    free(pd->file_content);
  exit(1);
  return (1);
}

void print_error(char *msg)
{
  write(2, msg, ft_strlen(msg));
}