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

#include <stdio.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	char **s_chunk;
	char **chunk;

	chunk = (char **) malloc(sizeof(char *));
	*chunk = NULL;
	s_chunk = provide_singleton(fd);
	printf ("[%s]", *s_chunk);
	if (fd < 0 || BUFFER_SIZE <= 0 || !chunk || !s_chunk)
		return (NULL);
	if (join_to_nl(fd, s_chunk, chunk))
		return (NULL); 
	return (*chunk);
}

//	printf("(nl:%s)\n", nl);
//	printf("[a:%ld]\n", nl - *chunk + 1);
//	printf("(s_c:%s)\n", *s_chunk);
//	printf("(c:%s)\n", *chunk); 
int join_to_nl(int fd, char **s_chunk, char **chunk)
{
	char *nl;
	char *join;
	int bread;

	nl = ft_strchr(*s_chunk, '\n');
	if (nl)
	{
		*chunk = *s_chunk;	
		*s_chunk = NULL;
	}
	while (!nl)
	{
		bread = read_buffer(fd, chunk);
		if (bread <= 0)
			return (1);
		else if (bread < BUFFER_SIZE)
		{
			join = ft_strjoin(s_chunk, chunk, ft_strlen(*chunk));
			*s_chunk = join;
			return (1);
		}
		nl = ft_strchr(*chunk, '\n');
		if (!nl)
		{
			join = ft_strjoin(s_chunk, chunk, BUFFER_SIZE);
		if (!join)
				return (1);
			else
				*s_chunk = join;
			if (!join)
				return (1);
		}
	}
	join = ft_strjoin(s_chunk, chunk, (nl - *chunk + 1));
		*s_chunk = join;
	if (!join)
		return (1);
	*chunk = *s_chunk;
	nl++;
	*s_chunk = nl;
	return (0);
}

int read_buffer(int fd, char **chunk)
{
	char *buf;
	int bread;

	buf = (char *) malloc(BUFFER_SIZE + 1);
	bread = read(fd, buf, BUFFER_SIZE - 1);
	buf[BUFFER_SIZE] = '\0';
	*chunk = buf;
	return (bread);
}

char **provide_singleton(int fd)
{
	static int sfd;
	static char **chunk;

	if (sfd != fd || !sfd)
	{
		sfd = fd;
		if (chunk)
		{
			if (*chunk)
				free(*chunk);
			free(chunk);
		}
	}
	if (!chunk)
	{
		chunk = (char **) malloc(sizeof(char *));
		*chunk = NULL;
	}
	return (chunk);
}

char *free_params(char **chunk, char **s_chunk)
{
    char *out;

    if (chunk)
    {
        if (*chunk)
            free (*chunk);
        free(chunk);
    }
    if (s_chunk)
    {
        out = *chunk;
        free (s_chunk);
        return (out);
    }
    (void) s_chunk;
    return (NULL);
}
