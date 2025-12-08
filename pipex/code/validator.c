#include "pipex.h"

void validate_data(t_data *data)
{
  int flag;
  char *path;
  int i;
  int j;

  if (access(data->infile, R_OK))
    end(data, "infile not found\n");
  if (access(data->outfile, W_OK))
    end(data, "outfile not found\n");

  i = 0;
  while (i < data->cmd_count)
  {
    j = 0;
    flag = 0;
    while (data->paths[j])
    {
      path = ft_strjoin(data->paths[j], data->cmd[i].name);
      if(!path)
        end(data, "malloc error\n");
      if (access(path, X_OK) == 0)
        break;
      free(path);
      j++;
    }
    if (!data->paths[j])
      end(data, "command not found on path\n");
    data->cmd[i].path = path;
    i++;
  }
}