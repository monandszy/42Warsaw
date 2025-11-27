
#include "client.h"

static volatile sig_atomic_t g_flag = 0;

void confirmation_handler(int signum)
{
  (void)signum;
  g_flag = 1;
}

void process_string(pid_t pid, char *str)
{
  int i;

  while (*str)
  {
    i = 0;
    while (i < 8)
    {
      g_flag = 0;
      if (*str & (1 << i))
        kill(pid, SIGUSR1);
      else
        kill(pid, SIGUSR2);
      while (!g_flag)
        pause(); 
      i++;
    }
    str++;
  }
}

int main(int argc, char **argv)
{
  if (argc != 3)
  {
    ft_printf("---ARGS---\n");
    ft_printf("1. PID\n");
    ft_printf("2. String to send\n");
    return (1);
  }
  if (!ft_isnumber(argv[1]))
    return (ft_printf("Invalid PID\n"), 1);
  signal(SIGUSR1, confirmation_handler);
  process_string((pid_t)ft_atoi(argv[1]), argv[2]);
  return (0);
}