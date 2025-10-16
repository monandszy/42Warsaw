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
	char *buf;
	static int sfd;
	static char *prev;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (sfd != fd || !sfd)
	{
		sfd = fd;
		if (prev)
			free (prev);
		prev = NULL;
	}
	printf("[%d]", sfd);
	printf("[%d]", fd);
	printf("[%d]", BUFFER_SIZE);
	buf = (char *) malloc(BUFFER_SIZE);
	printf("[%zu]", sizeof(buf));
	read(fd, buf, BUFFER_SIZE - 2);
	buf[BUFFER_SIZE - 1] = '\0';
	return (buf);
}
