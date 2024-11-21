/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 12:07:23 by davi              #+#    #+#             */
/*   Updated: 2024/09/27 14:30:17 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
//#include <stdio.h>

char	*mallockiller(char *s1, char *s2)
{
	free(s1);
	free(s2);
	s2 = NULL;
	return (0);
}

char	*before_newline(char *str)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_get_substr (str, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*after_newline(char *str)
{
	char	*result;
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (free(str), NULL);
	while (str[i] != '\n' && str[i])
		i++;
	if (str[i] == '\n')
		i++;
	result = ft_get_substr (str, i, ft_get_strlen(str) - i);
	free(str);
	if (!result[0])
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*result[FD_MAX];
	char		*buffer;
	int			nb_count;

	nb_count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (nb_count != 0 && !(ft_get_strchr(result[fd], '\n')))
	{
		nb_count = read(fd, buffer, BUFFER_SIZE);
		if (nb_count == -1)
		{
			result[fd] = mallockiller(buffer, result[fd]);
			return (NULL);
		}
		buffer[nb_count] = '\0';
		result[fd] = ft_get_strjoin(result[fd], buffer);
	}
	free(buffer);
	buffer = before_newline(result[fd]);
	result[fd] = after_newline(result[fd]);
	return (buffer);
}
