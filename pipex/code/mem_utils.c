#include "pipex.h"

void end(t_data *data, char *str)
{
  int i;
  if (data->argv_split)
    free(data->argv_split);
  if (data->paths)
    f_sp(data->paths);
  if (data->cmd)
  {
    i = 0;
    while (i < data->cmd_count)
    {
      f_sp(data->cmd[i].params);
      free(data->cmd[i].name);
      free(data->cmd[i].path);
      i++;
    }
    free(data->cmd);
  }
  if (str)
  {
    write(STDERR_FILENO, str, ft_strlen(str));
    exit(1);
  }
  exit(0);
}

void	f_sp(char **sp)
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
