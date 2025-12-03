/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 11:31:04 by sandrzej          #+#    #+#             */
/*   Updated: 2025/11/28 11:31:06 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    while(i < data->cmd_count)
    {
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
      if (access(path, X_OK) == 0)
        break;
      free(path);
      j++;
    }
    if (!data->paths[j])
      end(data, "command not found on path\n");
    printf("%s\n", path);
    data->cmd[i].path = path;
    i++;
  }
}

int main(int argc, char **argv, char **envp)
{
  static t_data data;
 
  if (argc < 4)
    end(&data, "argc error\n");
  initalize(&data, argc, argv, envp);
  validate_data(&data);
  end(&data, NULL);
}