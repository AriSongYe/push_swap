/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yecsong <yecsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 12:15:59 by yecsong           #+#    #+#             */
/*   Updated: 2022/11/02 15:59:09 by yecsong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*store;
	char		*line;
	char		*temp;
	int			end;

	end = 0;
	temp = read_line(fd, store, &end);
	if (!temp || end == 0)
	{
		free(temp);
		store = NULL;
		return (NULL);
	}
	line = my_ft_strdup(temp, end);
	store = my_ft_strdup(temp + end, my_ft_strlen (temp + end));
	free(temp);
	return (line);
}

char	*read_line(int fd, char *store, int *end)
{
	char	*buff;
	int		n;

	if (store && my_ft_strchr(store, end))
		return (store);
	if (store)
		*end = my_ft_strlen(store);
	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (1)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == 0 || n == -1)
			break ;
		buff[n] = '\0';
		store = my_ft_strjoin(store, buff);
		if (!store || my_ft_strchr(store, end))
			break ;
		*end += n;
	}
	free(buff);
	return (store);
}

char	*my_ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*ptr;

	s1_len = 0;
	if (s1)
		s1_len = my_ft_strlen(s1);
	s2_len = my_ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) *(s1_len + s2_len + 1));
	if (!ptr)
		return (NULL);
	my_ft_strlcpy(ptr, s1, s1_len + 1);
	my_ft_strlcpy(ptr + s1_len, s2, s2_len + 1);
	free(s1);
	return (ptr);
}

int	my_ft_strchr(const char *s, int *end)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			*end = i + 1;
			return (1);
		}
		i++;
	}
	return (0);
}
