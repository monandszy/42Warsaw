
#include "server.h"

void signal_handler(int signum, siginfo_t *info, void *context)
{
  static unsigned char c = 0;
  static int i = 0;
  (void)context;

  if (signum == SIGUSR1)
    c |= (1 << i);
  i++;
  if (i == 8)
  {
    ft_printf("%c", c);
    i = 0;
    c = 0;
  }
  if (info->si_pid)
    kill(info->si_pid, SIGUSR1);
}

int main(void)
{
  struct sigaction sa;

  ft_printf("PID: %d\n", getpid());
  sa.sa_sigaction = signal_handler;
  sa.sa_flags = SA_SIGINFO;
  sigemptyset(&sa.sa_mask);
  sigaddset(&sa.sa_mask, SIGUSR1);
  sigaddset(&sa.sa_mask, SIGUSR2);
  sigaction(SIGUSR1, &sa, NULL);
  sigaction(SIGUSR2, &sa, NULL);
  while (1)
    pause();
  return (0);
}