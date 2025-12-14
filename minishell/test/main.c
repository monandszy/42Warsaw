
#include "./../code/minishell.h"

volatile int	g_SHLVL = 0;

void free_cmd(t_cmd *cmd)
{
  free_split(cmd->args);
  free(cmd); 
}


void test(t_shell *shell, char *in)
{
  t_cmd *cmd;

  errno = 0;
  printf("START: [%s]\n", in);
  cmd = init_single_cmd(shell, in);
  execute_cmd_chain(shell, cmd);
  free_cmd(cmd);
  printf("END: [%s]\n", in);
  // perror("");
}

int main(int argc, char **argv, char **envp)
{
  t_shell shell;

  (void) argv;
  (void) argc;

  init_shell(&shell, envp);
  // test(&shell, "./testexe");
  // test(&shell, "/bin/ls");  
  // test(&shell, "make");
  // test(&shell, "          ");
  // test(&shell, "");
  // test(&shell, "none");
  // test(&shell, "echo -n cat");
  // test(&shell, "echo cat");


  // test(&shell, "env");
  // test(&shell, "export CAT=firstcat feaffa");
  // test(&shell, "env");
  // test(&shell, "export CAT=secondcat");
  // test(&shell, "env");
  // test(&shell, "unset CAT");
  // test(&shell, "env");

  // test(&shell, "export");
  // test(&shell, "unset");

  // test(&shell, "dir");
  // test(&shell, "pwd");
  // test(&shell, "cd ..");
  // test(&shell, "pwd");
  // test(&shell, "cd test");
  // test(&shell, "pwd");
  // test(&shell, "cd");
  // test(&shell, "pwd");

  // test(&shell, "unset PATH");
  // test(&shell, "dir");
  // test(&shell, "/bin/ls");
  // test(&shell, "export PATH=/bin:/home/user/new/minishell/test");
  // test(&shell, "ls");
  test(&shell, "exit random arsgument stuff");
  end(&shell, NULL);
}