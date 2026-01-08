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

int error(t_parser_data *pd, char *msg)
{
  size_t i;
  size_t len;

  print_error(msg);
  fflush(stdout);
  if (pd->parts)
    free_split(pd->parts);
  if (pd->objects)
  {
    len = split_len(pd->objects);
    if (pd->entries)
    {
      i = 0;
      while (i < len)
      {
         if (pd->entries[i].obj)
           free(pd->entries[i].obj);
         i++;
      }
      free(pd->entries);
    }
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