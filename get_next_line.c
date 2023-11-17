/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:41:45 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/17 12:05:29 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*get_extra(int fd, char	*extra)
{
	int		bytes;
	char	*buff;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (bytes != 0 && !ft_strchr(extra, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[bytes] = 0;
		extra = ft_strjoin(extra, buff);
	}
	free(buff);
	return (extra);
}

char	*get_line(char	*buff)
{
	char	*str;
	int		i;

	i = 0;
	if (!buff[i])
		return (NULL);
	while (buff[i] && buff[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (buff[i] && buff[i] != '\n')
	{
		str[i] = buff[i];
		i++;
	}
	if (buff[i] == '\n')
	{
		str[i] = '\n';
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*new_extra(char	*buff)
{
	char	*str;
	int		i;
	int		j;

	while (buff[i] && buff[i] != '\n')
		i++;
	if (buff[i] == '\n')
		i++;
	if (!buff[i])
	{
		free(buff);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(buff) - i + 1));
	if (!str)
		return (NULL);
	j = 0;
	while (buff[i])
		str[j++] = buff[i++];
	str[j] = 0;
	free(buff);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*extra;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	extra = get_extra(fd, extra);
	if (!extra)
		return (NULL);
	line = get_line(extra);
	extra = new_extra(extra);
	return (line);
}
