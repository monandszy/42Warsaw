
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		join_to_nl(int fd, char **s_chunk, char **chunk);
int		read_buffer(int fd, char **chunk);
char	**provide_singleton(int fd, int *end);
void	free_params(char **chunk);
char	*ft_strjoin(char *s1, char *s2, size_t s2_len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strchr(char *s, char needle);
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

void	process_nl(size_t nlpos, char **s_chunk, char **chunk, int bread);

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 8192
#endif

#endif


