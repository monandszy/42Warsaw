#!/bin/bash
echo "echo hello | cat" | valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp --log-file=valgrind_pipe.log ./minishell
cat valgrind_pipe.log

echo "export TEST=123
echo \$TEST
unset TEST" | valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp --log-file=valgrind_env.log ./minishell
cat valgrind_env.log
