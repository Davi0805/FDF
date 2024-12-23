/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 00:57:49 by davi              #+#    #+#             */
/*   Updated: 2024/11/22 00:58:55 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../Libft/get_next_line/get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include "data_structs.h"

int	count_columns(char const *str, char c)
{
	int	i;
	int	contador;

	i = 0;
	contador = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			contador++;
			while (str[i] && str[i] != c)
				i++;
		}
		else if (str[i] == c)
			i++;
	}
	return (contador);
}

void	map_size(char *filename, t_main_data *data)
{
	int		fd;
	char	*line;

	data->map_data.lines_count = 0;
	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	data->map_data.column_count = count_columns(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		data->map_data.lines_count++;
	}
	free(line);
	close(fd);
	return ;
}
