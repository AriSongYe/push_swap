/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 11:00:29 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 15:59:02 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 10
# include <stdlib.h>
# include <unistd.h>

char	*read_line(int fd, char *store, int *end);
char	*my_ft_strjoin(char *s1, char *s2);
char	*my_ft_strdup(const char *s1, int size);
size_t	my_ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		my_ft_strchr(const char *s, int *end);
int		my_ft_strlen(const char *s);
char	*get_next_line(int fd);

#endif
