/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:09:13 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/24 10:28:23 by gad              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char const *extra, char const *buff);
int		ft_strlen(char	const *str);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
#endif
