/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:39:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/17 12:39:34 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../minishell.h"

int	validate_command(t_shell *shell, t_cmd *cmd)
{
	char	*path;
	char	*name;

	path = NULL;
	name = cmd->args[0];
	if (ft_strncmp("./", name, 2) == 0)
		path = validate_as_rel(shell, cmd);
	else if (ft_strncmp("~/", name, 2) == 0)
		path = validate_as_user(shell, cmd);
	else if (ft_strncmp("/", name, 1) == 0)
		path = validate_as_is(shell, name);
	else
		path = validate_in_paths(shell, name);
	cmd->path = path;
	if (!path)
		return (shperror(cmd->args[0], "command not found"),
			shell->exit_code = 127, 1);
	if (validate_access(cmd, path))
		return (shell->exit_code = 126, 1);
	return (0);
}
