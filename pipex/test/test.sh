make -C ./../code
cp ./../code/pipex ./pipex

valgrind --leak-check=full ./pipex infile "ls -la" "wc -l" outfile
