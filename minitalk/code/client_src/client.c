
#include "client.h"

void process_string(pid_t pid, char *str)
{
  (void) pid;
  (void) str;
  kill(pid, SIGUSR1);
  kill(pid, SIGUSR2);
}

int main(int argc, char **argv)
{

  if (argc == 3)
  {
    if (!ft_isnumber(argv[1]))
      return(ft_printf("Invalid PID\n"), 1);
    process_string((pid_t) ft_atoi(argv[1]), argv[2]);
    return (0);
  }
  ft_printf("---ARGS---\n");
  ft_printf("1. PID\n");
  ft_printf("2. String to send\n");
  return(1);
}
