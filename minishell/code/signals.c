/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 12:34:59 by sandrzej          #+#    #+#             */
/*   Updated: 2025/12/17 12:36:30 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern int	g_shlvl;

void	handle_sigint(int sig)
{
	(void)sig;
	if (g_shlvl == 0)
	{ 
		write(1, "^C\n", 4);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
  else if (g_shlvl == -1)
  {
    g_shlvl = 0;
    rl_replace_line("", 0); 
    rl_done = 1;
    ioctl(STDIN_FILENO, TIOCSTI, "\n");
  }
	else
		write(1, "\n", 1);
}

void	handle_sigquit(int sig)
{
	(void)sig;
}

// void	disable_control(t_shell *shell)
// {
// 	struct termios	t;

// 	ft_bzero(&t, sizeof(t));
// 	tcgetattr(STDIN_FILENO, &t);
// 	shell->t = t;
// 	t.c_lflag &= ~ECHOCTL;
// 	tcsetattr(STDIN_FILENO, TCSANOW, &t);
// }

// disable_control(shell);
void	setup_signals(t_shell *shell)
{
  (void) shell;
	rl_catch_signals = 0;
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
}
