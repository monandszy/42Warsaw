
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

void test_t(t_shell *shell, char *s1, char *s2)
{
  errno = 0;
  t_cmd *c1 = init_single_cmd(shell, s1);
  t_cmd *c2 = init_single_cmd(shell, s2);
  c1->next = c2;
  shell->cmds = c1;
  printf("START: [%s][%s]\n", s1, s2);
  execute_cmd_chain(shell, c1);
  free_cmd(c1);
  free_cmd(c2);
  printf("END: [%s][%s]\n", s1, s2);
}

void test_m(t_shell *shell, char *s1, char *s2, char *s3)
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

void test_multiple(t_shell *shell)
{
  test_m(shell, "dir", "dir", "dir");
  
   // ls | grep ".c" | wc -l
  test_m(shell, "ls", "grep .c", "wc -l");
  // cat Makefile | head -n 10 | tail -n 1
  test_m(shell, "cat Makefile", "head -n 10", "tail -n 1");
  // echo "HelloWorld" | tr "H" "Y" | cat -e
  test_m(shell, "echo HelloWorld", "tr H Y", "cat -e");
  // ps aux | grep "usr" | sort -r
  test_m(shell, "ps aux", "grep usr", "sort -r");

    // echo "1 2 3" | tr ' ' '\n' | grep 2
  // (Note: C requires double backslash for newline escape)
  // test_m(shell, "echo 1 2 3", "tr ' ' '\\n'", "grep 2");
}

void test_two(t_shell *shell)
{
  // ls -la | wc -l
  test_t(shell, "ls -la", "wc -l");
  // cat /etc/passwd | head -n 5
  test_t(shell, "cat /etc/passwd", "head -n 5");
  // echo "hello world" | cat -e
  test_t(shell, "echo hello world", "cat -e");
  // who | sort
  test_t(shell, "who", "sort");

  // yes | head -n 5
  // (Tests if the pipe closes correctly to stop the infinite 'yes')
  // test_t(shell, "yes", "head -n 5");
  // ls | echo "I ignore input"
  // (Tests if the first process finishes even if the second ignores stdin)
  test_t(shell, "ls", "echo I ignore input");
  // sleep 1 | ls
  // (Tests concurrency/waiting)
  test_t(shell, "sleep 1", "ls");
}

t_redir *init_redir(t_shell *shell, char *file, t_token_type t)
{
  t_redir *new;

	new = (t_redir *)malloc(sizeof(t_redir));
	if (!new)
		end(shell, "redir init error\n");
	new->file = file;
  new->type=t;
  new->next=NULL;
  return (new);
}

void test_r(t_shell *shell, char *s1, char *s2, t_token_type t1, t_token_type t2)
{
  char *infile = "testinput";
  char *outfile = "testoutput";

  t_cmd *c1 = init_single_cmd(shell, s1);
  t_cmd *c2 = init_single_cmd(shell, s2);
  c1->next = c2;
  t_redir *r1 = init_redir(shell, infile, t1);
  t_redir *r2 = init_redir(shell, outfile, t2);
  c1->redirs=r1;
  c2->redirs=r2;
  shell->cmds=c1;
  printf("START: [%s][%s]\n", s1, s2);
  execute_cmd_chain(shell, c1);
  free_cmd(c1);
  free_cmd(c2);
  free(r1);
  free(r2);
  printf("END: [%s][%s]\n", s1, s2);
}

void test_redir(t_shell *shell)
{
  // SCENARIO 1: Standard Input -> Standard Output
  // Shell equivalent: < testinput cat | cat > testoutput
  // Description: Reads content from 'testinput', pipes it, and overwrites 'testoutput'.
  // test_r(shell, "cat", "cat", TOKEN_REDIR_IN, TOKEN_REDIR_OUT);

  // SCENARIO 2: Standard Input -> Append Output
  // Shell equivalent: < testinput grep "a" | cat >> testoutput
  // Description: Filters lines from 'testinput' containing "a", and appends them to 'testoutput'.
  // test_r(shell, "grep a", "cat", TOKEN_REDIR_IN, TOKEN_REDIR_APPEND);

  // SCENARIO 3: Heredoc -> Standard Output
  // Shell equivalent: << delimiter cat | wc -l > testoutput
  // Description: Reads from heredoc (delimiter defined in your redir logic), counts lines, writes result to 'testoutput'.
  // test_r(shell, "cat", "wc -l", TOKEN_REDIR_HEREDOC, TOKEN_REDIR_OUT);

  // SCENARIO 4: Outputting to 'testinput' (Reverse logic)
  // Shell equivalent: ls > testinput | wc > testoutput
  // Description: c1 overwrites 'testinput' (acting as a log file here) while sending output down the pipe to c2.
  // Note: Depending on your pipe logic, 'wc' might see nothing if 'ls' redirects stdout to file.
  // test_r(shell, "ls", "wc", TOKEN_REDIR_OUT, TOKEN_REDIR_OUT);

  // SCENARIO 5: Append to 'testinput' -> Append to 'testoutput'
  // Shell equivalent: echo "log" >> testinput | echo "done" >> testoutput
  // Description: Both commands append to their respective files. Pipe might convey empty data if stdout is redirected.
  test_r(shell, "echo log", "echo done", TOKEN_REDIR_APPEND, TOKEN_REDIR_APPEND);
}

int main(int argc, char **argv, char **envp)
{
  t_shell shell;

  (void) argv;
  (void) argc;

  init_shell(&shell, envp);

  // test_single(&shell);
  // test_two(&shell);
  // test_multiple(&shell);

  // cat | cat | ls
  // (creates a chain where the final command ignores the previous output)
  // test_m(&shell, "cat", "cat", "ls");

  test_redir(&shell);
 
  // printf("END");
  // fflush(stdout);
  // while(1)
  //   ;
  // read(0, " ", 1);

  test(&shell, "exit random arsgument stuff");
  end(&shell, NULL);
}