#include "minilibx-linux/mlx.h"
#include <fcntl.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "Libft/libft.h"
#include <string.h>
#include "Libft/get_next_line.h"

#define MAP_WIDTH 50
#define MAP_HEIGHT 50

int line_counter (char *filename)
{
	int fd;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "ERRO NO FD\n", 12);
		return (1);
	}
	int count = 0;
	char *line;

	/* printf("Inciando LOOp"); */
	while(get_next_line(fd))
		count++;
	/* printf("Linhas: %i", count); */
/* 	write(1, ft_itoa(count), sizeof(ft_itoa(count)));
	write(1, "\n", 1); */

	return (count);
}

/* int parse_map (char *filename, int num_lines)
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
} */

char ***parse_map (char *filename, int num_lines)
{
    int fd;
    int i;
    char ***lines;

    // Allocate memory for lines
    lines = (char ***)malloc(sizeof(char **) * num_lines);
    if (!lines)
    {
        printf("LOG: ERRO NO MEMORIA");
        return (NULL);
    }

    i = 0;
    fd = open(filename, O_RDONLY);

    if (fd == -1)
    {
        printf("LOG: ERRO NO FD");
        free(lines);
        return (NULL);
    }

    while (i < num_lines)
    {
        lines[i] = ft_split(get_next_line(fd), ' ');
        if (!lines[i])
        {
            printf("LOG: ERRO NO SPLIT");
            // Free previously allocated memory
            for (int j = 0; j < i; j++)
            {
                for (int k = 0; lines[j][k]; k++)
                {
                    free(lines[j][k]);
                }
                free(lines[j]);
            }
            free(lines);
            return (NULL);
        }

/*         // Print the contents of the strings in lines[i]
        for (int j = 0; lines[i][j]; j++)
        {
            write(1, lines[i][j], strlen(lines[i][j]));
            write(1, "\n", 1);
        } */

        i++;
    }

    // Free allocated memory
    /* for (int j = 0; j < num_lines; j++)
    {
        for (int k = 0; lines[j][k]; k++)
        {
            free(lines[j][k]);
        }
        free(lines[j]);
    }
    free(lines); */

    return (lines);
}

typedef struct s_coord {
    int x;
    int y;
    int z;
}   t_coord;

typedef struct s_mlx_data {
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
}   t_mlx_data;

void    my_pixel_put(t_mlx_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->img_ptr + (y * MAP_WIDTH + x * 4);
    *(unsigned int*)dst = color;
}

void    bresenhamn(t_coord *source, t_coord *destination, t_coord *points, int *points_index)
{
    int dx = abs(destination->x - source->x);
    int dy = abs(destination->y - source->y);
    int sx = (source->x < destination->x) ? 1 : -1;
    int sy = (source->y < destination->y) ? 1 : -1;
    int err = dx - dy;

    points[0].x = source->x;
    points[0].y = source->y;
    (*points_index)++;

    while (source->x != destination->x || source->y != destination->y)
    {
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            source->x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            source->y += sy;
        }
        points[(*points_index)].x = source->x;
        points[(*points_index)].y = source->y;
        (*points_index)++;
    }
}

void    drawline_helper(t_mlx_data *data, t_coord *source, t_coord *destination, int color, int orient)
{
    t_coord points[1000];
    int points_index = 0;
    int i;

    i = 0;

    bresenhamn(source, destination, points, &points_index);

    while (i < points_index)
    {
        my_pixel_put(data, points[i].x, points[i].y, color);
        i++;
    }
}

/* void    drawline(t_mlx_data *data, int map_data[MAP_HEIGHT][MAP_WIDTH])
{
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map_data[y][x] == 10) {
                if (x < MAP_WIDTH - 1 && map_data[y][x + 1] == 10) {
                    t_coord inicio;
                    t_coord fim;
                    inicio.x = x;
                    inicio.y = y;
                    fim.x = x + 1;
                    fim.y = y;
                    drawline_helper(data, &inicio, &fim, 0x00FF0000, 1);
                }
                if (y < MAP_HEIGHT - 1 && map_data[y + 1][x] == 10) {
                    t_coord inicio;
                    t_coord fim;
                    inicio.x = x;
                    inicio.y = y;
                    fim.x = x;
                    fim.y = y + 1;
                    drawline_helper(data, &inicio, &fim, 0x00FF0000, 1);
                }
            }
        }
    }
} */

void    drawline(t_mlx_data *data, char ***lines)
{
    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
            if (map_data[y][x] == 10) {
                if (x < MAP_WIDTH - 1 && map_data[y][x + 1] == 10) {
                    t_coord inicio;
                    t_coord fim;
                    inicio.x = x;
                    inicio.y = y;
                    fim.x = x + 1;
                    fim.y = y;
                    drawline_helper(data, &inicio, &fim, 0x00FF0000, 1);
                }
                if (y < MAP_HEIGHT - 1 && map_data[y + 1][x] == 10) {
                    t_coord inicio;
                    t_coord fim;
                    inicio.x = x;
                    inicio.y = y;
                    fim.x = x;
                    fim.y = y + 1;
                    drawline_helper(data, &inicio, &fim, 0x00FF0000, 1);
                }
            }
        }
    }
}

int main()
{
	char ***lines = parse_map("42.fdf", line_counter("42.fdf"));

	write(1, lines[0][0], ft_strlen(lines[10][0]));



    t_mlx_data data;
    data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == 0)
	{
		printf("Erro ao iniciar!");
		return (1);
	}
    data.win_ptr = mlx_new_window(data.mlx_ptr, MAP_WIDTH * 10, MAP_HEIGHT * 10, "FDF - DMELO-CA");
    data.img_ptr = mlx_new_image(data.mlx_ptr, MAP_WIDTH * 10, MAP_HEIGHT * 10);

    drawline(&data, lines);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);

    mlx_loop(data.mlx_ptr);

    return 0;
}
