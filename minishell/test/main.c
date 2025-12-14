
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
  shell->cmds = cmd;
  execute_cmd_chain(shell, cmd);
  free_cmd(cmd);
  printf("END: [%s]\n", in);
}

void test_single(t_shell *shell)
{
  test(shell, "./testexe");
  test(shell, "/bin/ls");  
  test(shell, "make");
  test(shell, "          ");
  test(shell, "");
  test(shell, "none");
  test(shell, "echo -n cat");
  test(shell, "echo cat");

  test(shell, "env");
  test(shell, "export CAT=firstcat feaffa");
  test(shell, "env");
  test(shell, "export CAT=secondcat");
  test(shell, "env");
  test(shell, "unset CAT");
  test(shell, "env");

  test(shell, "export");
  test(shell, "unset");

  test(shell, "dir");
  test(shell, "pwd");
  test(shell, "cd ..");
  test(shell, "pwd");
  test(shell, "cd test");
  test(shell, "pwd");
  test(shell, "cd");
  test(shell, "pwd");

  test(shell, "unset PATH");
  test(shell, "dir");
  test(shell, "/bin/ls");
  test(shell, "export PATH=/bin:/home/user/new/minishell/test");
  test(shell, "ls");
}

void test_mutliple(t_shell *shell, char *s1, char *s2, char *s3)
{
  errno = 0;
  t_cmd *c1 = init_single_cmd(shell, s1);
  t_cmd *c2 = init_single_cmd(shell, s2);
  t_cmd *c3 = init_single_cmd(shell, s3);
  c1->next = c2;
  c2->next = c3;
  shell->cmds = c1;
  printf("START: [%s][%s][%s]\n", s1, s2, s3);
  execute_cmd_chain(shell, c1);
  free_cmd(c1);
  free_cmd(c2);
  free_cmd(c3);
  printf("END: [%s][%s][%s]\n", s1, s2, s3);
}

int main(int argc, char **argv, char **envp)
{
  t_shell shell;

  (void) argv;
  (void) argc;

  init_shell(&shell, envp);
  // setup_signals();
  // test_single(&shell);
  test_mutliple(&shell, "dir", "dir", "dir");
  test(&shell, "exit random arsgument stuff");
  end(&shell, NULL);
}