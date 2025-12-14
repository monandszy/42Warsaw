#include "./../minishell.h"

<<<<<<< HEAD
int	change_directory(t_shell *shell, t_cmd *cmd)
=======
void	change_directory(t_shell *shell, t_cmd *cmd)
>>>>>>> refs/remotes/origin/master
{
	char *to;

	to = cmd->args[1];
	if (!to)
	{
		to = env_get(&shell->env_list, "HOME");
		if (!to)
<<<<<<< HEAD
			return (1);
	}
	chdir(to);
  return (0);
=======
			return ;
	}
	chdir(to);
>>>>>>> refs/remotes/origin/master
}