/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:52:46 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/17 12:12:19 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s, char *buff)
{
	char				*str;
	unsigned int		i;

	if (!s)
	{
		s = malloc(sizeof(char) * 1);
		s[0] = 0;
	}
	if (!s || !buff)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(buff) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (s)
		while (*s)
			str[i++] = *s++;
	while (*buff)
		str[i++] = *buff++;
	str[ft_strlen(s) + ft_strlen(buff)] = 0;
	free(s);
	return (str);
}

char	*ft_strchr(char *s, int c)
{
	int				i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == 0)
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
