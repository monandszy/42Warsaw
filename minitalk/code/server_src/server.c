
#include "server.h"

void handler(int signo)
{
  if (signo == SIGUSR1)
  {
    ft_printf("true\n");
  }
  else if (signo == SIGUSR2)
  {
    ft_printf("false\n");
  }
}

int main(void)
{
  pid_t pid;
  struct sigaction action;
  sigset_t set;

  sigemptyset(&set);
  sigaddset(&set, SIGUSR1);
  sigaddset(&set, SIGUSR2);

  action.sa_handler = handler;
  action.sa_mask = set;
  pid = getpid();
  ft_printf("%d\n", pid);
  sigaction(SIGUSR1, &action, NULL);
  sigaction(SIGUSR2, &action, NULL);
  read(STDIN_FILENO, "  ", 1);
}
