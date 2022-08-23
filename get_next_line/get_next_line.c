/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argafary <argafary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:39:08 by argafary          #+#    #+#             */
/*   Updated: 2022/03/21 16:44:10 by argafary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <errno.h>
#include <fcntl.h>

static char	*ft_zero_bytes(char **stash)
{
	char	*line;

	line = ft_strdup(*stash);
	free(*stash);
	*stash = NULL;
	return (line);
}

static char	*ft_check_stash(char **stash)
{
	char	*line;
	char	*temp;
	size_t	n;

	if (!(*stash))
		return (NULL);
	line = NULL;
	if (ft_strchr(*stash, '\n'))
	{
		n = ft_strchr(*stash, '\n') - *stash + 1;
		line = ft_substr(*stash, 0, n);
		temp = ft_strdup((*stash) + n);
		if (*temp == '\0')
		{
			free(temp);
			temp = NULL;
		}
		free(*stash);
		*stash = temp;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			buf[BUFFER_SIZE + 1];
	ssize_t			read_bytes;
	static char		*stash = NULL;
	char			*line;

	if (fd < 0 || fd > 65536 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_check_stash(&stash);
	if (line != NULL)
		return (line);
	read_bytes = 1;
	while (read_bytes != 0)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes == -1)
			return (NULL);
		buf[read_bytes] = '\0';
		if (read_bytes > 0)
			stash = ft_strjoin(stash, buf);
		line = ft_check_stash(&stash);
		if (line != NULL)
			return (line);
	}
	line = ft_zero_bytes(&stash);
	return (line);
}
