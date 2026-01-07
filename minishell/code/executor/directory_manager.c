/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:40:14 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/17 12:40:16 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

/* bufered wrapper for getcwd */
static char	*getcwdir(t_shell *shell)
{
	static char	buffer[PATH_MAX] = "";

	getcwd(buffer, sizeof(buffer));
	if (!*buffer)
		end(shell, "error getting cwd\n");
	return (buffer);
}

int	add_if_exists(t_shell *shell, char *okey, char *cwd)
{
	char	*key;
	char	*keye;
	t_env	*new_node;

	keye = ft_strjoin(okey, "=");
	key = ft_strjoin(keye, cwd);
	free(keye);
	new_node = new_env_node(key);
	free(key);
	if (!new_node)
		end(shell, "chdir new node malloc error\n");
	if (env_get(&shell->env_list, okey))
		return (env_add_back(&shell->env_list, new_node));
	return (0);
}

int	change_directory(t_shell *shell, t_cmd *cmd)
{
	char	*to;
	char	*tmp;

	to = cmd->args[1];
	if (!to)
	{
		to = env_get(&shell->env_list, "HOME");
		if (!to)
			to = "";
	}
	else if (cmd->args[2])
		return (shperror(cmd->args[0], " too many arguments"), 1);
	tmp = getcwdir(shell);
	if (chdir(to) == -1)
		return (perror(to), 1);
	add_if_exists(shell, "OLDPWD", tmp);
	add_if_exists(shell, "PWD", getcwdir(shell));
	return (0);
}

static void	run_child(t_shell *shell, t_cmd *cmd)
{
	if (cmd->fdin != STDIN_FILENO)
	{
		if (dup2(cmd->fdin, STDIN_FILENO) == -1)
			end(shell, "dup2 input fail");
		close(cmd->fdin);
	}
	if (cmd->fdout != STDOUT_FILENO)
	{
		if (dup2(cmd->fdout, STDOUT_FILENO) == -1)
			end(shell, "dup2 output fail");
		close(cmd->fdout);
	}
	printf("%s\n", getcwdir(shell));
	shell->exit_code = 0;
	end(shell, NULL);
}

int	pwd(t_shell *shell, t_cmd *cmd)
{
	int	pid;

	pid = fork();
	if (pid < 0)
		end(shell, "fork failed\n");
	else if (pid == 0)
		run_child(shell, cmd);
	else
	{
		if (cmd->fdout != STDOUT_FILENO)
			close(cmd->fdout);
	}
	return (0);
}
