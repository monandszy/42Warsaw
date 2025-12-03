rm -rf pipex
make -C ./../code
cp ./../code/pipex ./pipex

valgrind --leak-check=full --show-leak-kinds=all --leak-check=full ./pipex infile "ls -la" "wc -l" outfile
