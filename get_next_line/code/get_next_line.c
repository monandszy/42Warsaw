/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:09:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/10/16 17:44:15 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	char **s_chunk;
	char **chunk;

	chunk = (char **) malloc((char *));
	s_chunk = provide_singleton(fd);
	if (fd < 0 || BUFFER_SIZE <= 0 || !chunk || !s_chunk)
		return (free_params(chunk));
	if (!find_nl(s_chunk, chunk))
		return (free_params(chunk));
	return (*s_chunk);
}

char *free_params(char **chunk)
{
	if (chunk)
	{
		if (*chunk)
			free(*chunk);
		free(chunk);
	}
}

int find_nl(char **s_chunk, char **chunk)
{
	char *nl;
	char *join;

	nl = NULL
	while (!nl)
	{
		read_buffer(fd, chunk);
		nl = strnchr(chunk, '\n');
		if (!nl)
			join = strjoin(*s_chunk, *chunk, BUFFER_SIZE);
		else
			join = strjoin(*s_chunk, *chunk, nl - *chunk);
		if !(join)
			return (NULL);
		else
		{
			free (*s_chunk);
			*s_chunk = join;
		}
	}

	*chunk = *s_chunk;
	nl++;
	*s_chunk = nl;
	return (nl);
}

void read_buffer(int fd, char **chunk)
{
	char *buf;

	buf = (char *) malloc(BUFFER_SIZE + 2);
	buf[BUFFER_SIZE + 1] = '\0';
	read(fd, buf, BUFFER_SIZE);
	*chunk = buf;
}

char **singleton_manager(int fd)
{
	static int sfd;
	static char **chunk;

	if (sfd != fd || !sfd)
	{
		sfd = fd;
		free_params(chunk);
		chunk = NULL;
	}
	if (!chunk)
		chunk = (char **) malloc((char *));
	return (chunk);
}
