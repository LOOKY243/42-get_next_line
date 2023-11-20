/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:32:47 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/20 17:22:50 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"
#include <string.h>

static char	*get_extra(int fd, char *extra)
{
	int		bytes;
	char	*buff;
	char	*tmp;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1 || (bytes == 0 && !extra))
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = 0;
		tmp = ft_strjoin(extra, buff);
		free(extra);
		extra = tmp;
		if (strchr(extra, '\n'))
			break ;
	}
	free(buff);
	return (extra);
}

static char	*get_line(char	*extra)
{
	int		i;
	char	*line;

	i = 0;
	while (extra[i] && extra[i] != '\n')
		i++;
	if (extra[i] && extra[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (extra[i] && extra[i] != '\n')
	{
		line[i] = extra[i];
		i++;
	}
	if (extra[i] && extra[i] == '\n')
	{
		line[i] = extra[i];
		i++;
	}
	line[i] = 0;
	return (line);
}

static char	*new_extra(char *extra)
{
	char	*new;
	int		i[3];

	i[0] = 0;
	i[2] = 0;
	while (extra[i[0]] && i[2] != 1)
	{
		if (extra[i[0]] == '\n')
			i[2]++;
		i[0]++;
	}
	if (i[0] != ft_strlen(extra))
	{
		new = (char *)malloc(sizeof(char) * (ft_strlen(extra) - i[0] + 1));
		if (!new)
			return (NULL);
		i[1] = 0;
		while (extra[i[0]])
			new[i[1]++] = extra[i[0]++];
		new[i[1]] = 0;
		free(extra);
		return (new);
	}
	free(extra);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*extra[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	extra[fd] = get_extra(fd, extra[fd]);
	if (!extra[fd])
		return (NULL);
	line = get_line(extra[fd]);
	extra[fd] = new_extra(extra[fd]);
	return (line);
}
