#include "pipex.h"

char	**argv_split(char **argv, int argc)
{
	char	**spl;

	spl = (char **)malloc((argc + 1) * sizeof(char *));
	if (!spl)
		return (NULL);
	spl[argc] = NULL;
	argc--;
	while (argc >= 0)
	{
		spl[argc] = argv[argc];
		argc--;
	}
	return (spl);
}

void process_path(t_data *data, char **envp)
{
  int i;
  char *path;

  i = 0;
  while(envp[i])
  {
    if(ft_strncmp(envp[i], "PATH=", 5) == 0)
      break;
    i++;
  }
  if (!envp[i])
    end(data, "PATH not found \n");
  path = ft_substr(envp[i], 5, ft_strlen(envp[i]));
  data->paths = ft_split(path, ':');
  free(path);
  if (!data->paths)
    end(data, "malloc error\n");
}

void initalize_commands(t_data *data)
{
  int i;
  char **params;

  i = 0;
  while (i < data->cmd_count)
  {
    data->cmd[i].command = data->argv_split[i + 2];
    params = ft_split(data->cmd[i].command, ' ');
    if(!params)
      end(data, "malloc error\n");
    data->cmd[i].params = params;
    data->cmd[i].name = ft_strjoin("/", params[0]);
    i++;
  }
}

void initalize(t_data *data, int argc, char **argv, char **envp)
{
  data->argv_split = argv_split(argv, argc);
  if (!data->argv_split)
    end(data, "malloc error\n");
  data->infile = data->argv_split[1];
  data->outfile = data->argv_split[argc - 1];
  data->cmd_count = argc - 3;
  data->cmd = (t_command *) malloc(sizeof(t_command) * (data->cmd_count));
  if(!data->cmd)
    end(data, "malloc error\n");

  initalize_commands(data);
  process_path(data, envp);
}