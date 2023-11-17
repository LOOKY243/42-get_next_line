/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarre <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 10:41:59 by gmarre            #+#    #+#             */
/*   Updated: 2023/11/17 12:14:19 by gmarre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin(char *s, char *buff);
char	*ft_strchr(char *s, int c);
char	*get_next_line(int fd);
int		ft_strlen(char *str);
#endif
