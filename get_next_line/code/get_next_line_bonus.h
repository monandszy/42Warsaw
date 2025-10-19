/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:09:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/17 16:04:03 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

/* typedef struct s_buffer
{
	struct s_buffer	*next;
	int			fd;
	char		*content;
}				t_buffer;

void	free_buffer(t_buffer *data, t_buffer *i);
char			*get_next_line(int fd);
int				join_to_nl(int fd, char **s_chunk, char **chunk);
int				read_buffer(int fd, char **chunk);
t_buffer		*provide_singleton(t_buffer	*i, int fd);
void			free_params(char **chunk);
char			*ft_strjoin(char *s1, char *s2);
void			*ft_memcpy(void *dest, const void *src, size_t n);
size_t			ft_strchr(char *s, char needle);
size_t			ft_strlen(const char *s);
char			*ft_substr(char const *s, unsigned int start, size_t len);

void			process_nl(size_t nlpos, char **s_chunk, char **chunk); */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8192
# endif

#endif
