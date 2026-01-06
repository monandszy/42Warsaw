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

size_t split_len(char **spl)
{
  size_t len;

  len = 0;
  while (spl[len])
    len++;
  return (len);
}