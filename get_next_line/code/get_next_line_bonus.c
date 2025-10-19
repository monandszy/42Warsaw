/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:09:08 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/15 14:21:28 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* char	*get_next_line(int fd)
{
	static t_buffer	*i;
	t_buffer		*data;
	char			*chunk;

	chunk = NULL;
	data = provide_singleton(i, fd);
	if (!data)
		return (NULL);
	if (join_to_nl(data->fd, &(data->content), &chunk))
	{
		free(chunk);
		chunk = NULL;
	}
	else if (*chunk == '\0')
	{
		free_buffer(i, data);
		free(chunk);
		chunk = NULL;
	}
	return (chunk);
}

//	printf("(nl:%s)\n", nl);
//	printf("[a:%ld]\n", nl - *chunk + 1);
//	printf("(s_c:%s)\n", *s_chunk);
//	printf("(c:%s)\n", *chunk);

// has to free *chunk && s_chunk && *s_chunk
int	join_to_nl(int fd, char **s_chunk, char **chunk)
{
	size_t	nlpos;
	char	*join;
	int		bread;

	nlpos = ft_strchr(*s_chunk, '\n');
	if (nlpos)
	{
		*chunk = *s_chunk;
		*s_chunk = NULL;
	}
	while (!nlpos)
	{
		join = ft_strjoin(*s_chunk, *chunk);
		free(*s_chunk);
		free(*chunk);
		*s_chunk = join;
		bread = read_buffer(fd, chunk);
		if (bread == -1)
			return (1);
		nlpos = ft_strchr(*chunk, '\n');
		if (bread == 0)
			break ;
	}
	process_nl(nlpos, s_chunk, chunk);
	return (0);
}

int	read_buffer(int fd, char **chunk)
{
	char	*buf;
	int		bread;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bread = read(fd, buf, BUFFER_SIZE);
	if (bread < 0)
	{
		free(buf);
		return (-1);
	}
	buf[bread] = '\0';
	*chunk = buf;
	return (bread);
}

void	process_nl(size_t nlpos, char **s_chunk, char **chunk)
{
	char	*tmpprev;
	char	*tmpnext;

	tmpprev = ft_substr(*chunk, 0, nlpos);
	tmpnext = ft_substr(*chunk, nlpos, ft_strlen(*chunk));
	free(*chunk);
	if (s_chunk && *s_chunk)
	{
		*chunk = ft_strjoin(*s_chunk, tmpprev);
		free(tmpprev);
	}
	else
		*chunk = tmpprev;
	free(*s_chunk);
	*s_chunk = tmpnext;
}

t_buffer	*provide_singleton(t_buffer *i, int fd)
{
	t_buffer	*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = i;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_buffer *)malloc(sizeof(t_buffer));
	tmp->fd = fd;
	tmp->next = NULL;
	if (!i)
		i = tmp;
	return (tmp);
} */
