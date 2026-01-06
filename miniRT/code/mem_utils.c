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

void error()
{
  exit(1);
}

void print_error(char *msg)
{
  write(2, msg, ft_strlen(msg));
}