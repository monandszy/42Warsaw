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

// read from infile
// pass content to cmd1
// redirect cmd1 to pipe
// pass content to cmdx
// write to outfile

/* 
int p[2]; // p[0] read p[1] write
*/

void write_all(t_data *data, int fd, char *content)
{
  if (fd < 0)
    end(data, "invalid fd\n");
  write(fd, content, ft_strlen(content));
  close(fd);
}

char *read_all(t_data *data, int fd)
{
  int bread;
  char buffer[101];
  char *content;
  char *tmp;

  if (fd < 0)
    end(data, "invalid fd\n");
  bread = 1;
  content = NULL;
  while(bread > 0)
  {
    bread = read(fd, buffer, 100);
    buffer[bread] = '\0';
    tmp = content;
    content = ft_strjoin(content, buffer);
    if(!content)
        end(data, "malloc error\n");
    free(tmp);
  }
  close(fd);
  return (content);
}

void pipex(t_data *data, char **envp)
{
  int i;
  int pid;
  int fd[2];
  int fd2[2];
  char *content;

  i = 0;
  content = read_all(data, open(data->infile, O_RDONLY));
  while (i < data->cmd_count)
  {
    if (pipe(fd) == -1)
      end(data, "pipe fail");
    if (pipe(fd2) == -1)
      end(data, "pipe fail");
    pid = fork();
    if (pid < 0)
      end(data, "fork failed\n");
    else if (pid == 0)
    {
      close(fd2[1]);
      close(fd[0]);
      if (dup2(fd[1], STDOUT_FILENO) == -1)
        end(data, "dup2 fail"); // output
      close(fd[1]);
      if (dup2(fd2[0], STDIN_FILENO) == -1)
        end(data, "dup2 fail"); // input
      close(fd2[0]);
      execve(data->cmd[i].path, data->cmd[i].params, envp);
    }
    else {
      close(fd[1]);
      close(fd2[0]);
      write_all(data, fd2[1], content);
      close(fd2[1]);
      wait(NULL);
      free(content);
      content = read_all(data, fd[0]);
    }
    i++;
  }
  write_all(data, open(data->outfile, O_WRONLY), content);
  free(content);
}

int main(int argc, char **argv, char **envp)
{
  static t_data data;
 
  if (argc < 4)
    end(&data, "argc error\n");
  initalize(&data, argc, argv, envp);
  validate_data(&data);
  pipex(&data, envp);
  end(&data, NULL);
}