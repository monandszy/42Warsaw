/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:09:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/17 16:04:03 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		**s_chunk;
	char		**chunk;
	char		*out;
	static int	end;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chunk = (char **)malloc(sizeof(char *));
	if (!chunk)
		return (NULL);
	*chunk = NULL;
	s_chunk = provide_singleton(fd, &end);
	if (!s_chunk || join_to_nl(fd, s_chunk, chunk))
	{
		free(*chunk);
		free(chunk);
		return (NULL);
	}
	if (**chunk == '\0')
	{
		free(*s_chunk);
		free(s_chunk);
		free(*chunk);
		*chunk = NULL;
		end = 1;
	}
	out = *chunk;
	free(chunk);
	return (out);
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

	bread = 0;
	nlpos = ft_strchr(*s_chunk, '\n');
	if (nlpos)
	{
		*chunk = *s_chunk;
		*s_chunk = NULL;
		bread = ft_strlen(*chunk);
	}
	while (!nlpos)
	{
		join = ft_strjoin(*s_chunk, *chunk, bread);
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
	process_nl(nlpos, s_chunk, chunk, bread);
	return (0);
}

void	process_nl(size_t nlpos, char **s_chunk, char **chunk, int bread)
{
	char	*tmpprev;
	char	*tmpnext;

	tmpprev = ft_substr(*chunk, 0, nlpos);
	tmpnext = ft_substr(*chunk, nlpos, bread);
	free(*chunk);
	if (s_chunk && *s_chunk)
	{
		*chunk = ft_strjoin(*s_chunk, tmpprev, ft_strlen(tmpprev));
		free(tmpprev);
	}
	else
		*chunk = tmpprev;
	free(*s_chunk);
	*s_chunk = tmpnext;
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

char	**provide_singleton(int fd, int *end)
{
	static int	sfd;
	static char	**chunk;

	if (*end || sfd != fd || !chunk)
	{
		sfd = fd;
		if (!*end && chunk)
		{
			if (*chunk)
				free(*chunk);
			free(chunk);
		}
		chunk = (char **)malloc(sizeof(char *));
		if (!chunk)
			return (NULL);
		*chunk = NULL;
		*end = 0;
	}
	return (chunk);
}
