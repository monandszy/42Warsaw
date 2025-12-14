
#include "./../code/minishell.h"

volatile int	g_SHLVL = 0;

t_cmd	*init_single_cmd(t_shell *shell, char *line)
{
	char **args;
	t_cmd *new;

	args = ft_split(line, ' ');
	new = (t_cmd *)malloc(sizeof(t_cmd));
	if (!args || !new)
		end(shell, "single cmd init malloc error\n");
	new->args = args;
  new->next = NULL;
  new->redirs = NULL;
  new->path = NULL;
	return (new);
}

int main(int argc, char **argv, char **envp)
{
  t_shell shell;
  char *line;

  (void) argv;
  (void) argc;

  init_shell(&shell, envp);
  line = "dir";
  t_cmd *cmd = init_single_cmd(&shell, line);
  execute_cmd_chain(&shell, cmd);
  free_split(cmd->args);
  free(cmd);
  return (0);
}