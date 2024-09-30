#include "minilibx-linux/mlx.h"
#include <fcntl.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "Libft/ft_printf.h"
#include <string.h>
#include "Libft/get_next_line/get_next_line.h"

int line_counter (char *filename)
{
	int fd;
	fd = open(filename, O_RDONLY);
	int count = 0;
	char *line;
	while(line)
	{
		line = get_next_line(fd);
		count++;
	}
	printf("Linhas: %i", count);

	return (count);
}

int parse_map (char *filename, int num_lines)
{
	int fd;
	int i;
	char ***lines;

	i = 0;
	fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		printf("LOG: ERRO NO FD");
		return (1);
	}

	while (i < num_lines)
	{
		lines[i] = ft_split(get_next_line(fd), ' ');
		write(1, lines[i], sizeof(lines[i]));
		i++;
	}
}

int main(void)
{
	char ***lines = parse_map("42.fdf", line_counter("42.fdf"));

	return (0);
}
