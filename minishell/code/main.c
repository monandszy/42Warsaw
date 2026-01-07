/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:34:17 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/17 12:34:21 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile int	g_shlvl = 0;

static char	*read_input(t_shell *shell)
{
	char	*line;
	char	*next_line;

	line = readline("mini(sand)hell> ");
	if (!line)
		end(shell, NULL);
	g_shlvl = -1;
	while (check_unclosed_quote(line))
	{
		next_line = readline("> ");
		if (g_shlvl == 0)
			return (NULL);
		if (!next_line)
		{
			shperror("minishell", "while looking for matching quote");
			return (free(line), NULL);
		}
		line = ft_strjoin_free(line, "\n");
		line = ft_strjoin_free(line, next_line);
		free(next_line);
	}
	g_shlvl = 0;
	return (line);
}

void	process_line(char *line, t_shell *shell)
{
	t_token	*tokens;
	t_cmd	*cmds;

	add_history(line);
	tokens = tokenizer(line);
	if (tokens)
	{
		shell->tokens = tokens;
		cmds = parse_tokens(tokens, shell);
		if (cmds)
		{
			shell->cmds = cmds;
			execute_cmd_chain(shell, cmds);
			free_cmds(cmds);
			shell->cmds = NULL;
		}
		free_tokens(tokens);
		shell->tokens = NULL;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;

	init_shell(&shell, envp, argc, argv);
	setup_signals(&shell);
	while (1)
	{
		line = read_input(&shell);
		if (line && *line)
		{
			process_line(line, &shell);
			free(line);
		}
	}
}
