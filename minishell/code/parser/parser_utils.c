/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:34:47 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/30 14:01:52 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmd	*init_cmd(void)
{
	t_cmd	*cmd;

	cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->redirs = NULL;
	cmd->next = NULL;
	return (cmd);
}

void	cmd_add_back(t_cmd **head, t_cmd *new_cmd)
{
	t_cmd	*curr;

	if (!*head)
	{
		*head = new_cmd;
		return ;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = new_cmd;
}

int	add_cmd_arg(t_cmd *cmd, char *arg)
{
	int		i;
	int		count;
	char	**new_args;

	count = 0;
	if (cmd->args)
		while (cmd->args[count])
			count++;
	new_args = malloc(sizeof(char *) * (count + 2));
	if (!new_args)
		return (0);
	i = 0;
	while (i < count)
	{
		new_args[i] = cmd->args[i];
		i++;
	}
	new_args[i] = ft_strdup(arg);
	new_args[i + 1] = NULL;
	if (cmd->args)
		free(cmd->args);
	cmd->args = new_args;
	return (1);
}

char	*join_char(char *str, char c)
{
	char *new_str;
	int len;

	if (!str)
	{
		new_str = malloc(2);
		if (!new_str)
			return (NULL);
		new_str[0] = c;
		new_str[1] = '\0';
		return (new_str);
	}
	len = ft_strlen(str);
	new_str = malloc(len + 2);
	if (!new_str)
		return (free(str), NULL);
	ft_strlcpy(new_str, str, len + 1);
	new_str[len] = c;
	new_str[len + 1] = '\0';
	return (free(str), new_str);
}