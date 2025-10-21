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

char	*get_next_line(int fd)
{
	static char	*persisted[4096];
	int			bread;

	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	bread = read_buffer(fd, persisted);
	if (bread < 0 || (bread == 0 && (!persisted[fd] || !*persisted[fd])))
	{
		if (persisted[fd])
			free(persisted[fd]);
		persisted[fd] = NULL;
		return (NULL);
	}
	return (process_nl(&persisted[fd]));
}

int	read_buffer(int fd, char **persisted)
{
	int		bread;
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (-1);
	bread = 1;
	while (bread > 0 && !ft_strchr(persisted[fd], '\n'))
	{
		bread = read(fd, buf, BUFFER_SIZE);
		if (bread <= 0)
			break ;
		buf[bread] = '\0';
		tmp = persisted[fd];
		persisted[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (bread);
}

char	*process_nl(char **persisted)
{
	char	*line;
	char	*temp;
	char	*nlpos;

	nlpos = ft_strchr(*persisted, '\n');
	if (nlpos)
	{
		line = ft_substr(*persisted, 0, nlpos - *persisted + 1);
		temp = ft_strdup(nlpos + 1);
		free(*persisted);
		*persisted = temp;
		if (**persisted == '\0')
		{
			free(*persisted);
			*persisted = NULL;
		}
		return (line);
	}
	line = ft_strdup(*persisted);
	free(*persisted);
	*persisted = NULL;
	return (line);
}

char	*ft_strchr(const char *s, int c)
{
	char	*i;
	char	needle;

	if (!s)
		return (NULL);
	needle = (char)c;
	i = (char *)s;
	while (*i)
	{
		if (*i == needle)
			return (i);
		i++;
	}
	if (needle == '\0' && *i == '\0')
		return (i);
	return (NULL);
}
