#include "minilibx-linux/mlx.h"
#include <fcntl.h>
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>
#include "Libft/ft_printf.h"
#include <string.h>
#include "Libft/get_next_line/get_next_line.h"
#include "data_structs.h"
#include "fdf_utils.h"

#define MAP_WIDTH 50
#define MAP_HEIGHT 50

/* int line_counter (char *filename)
{
	int fd;
	int count;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "ERRO NO FD\n", 12);
		return (1);
	}


	while(get_next_line(fd))
		count++;

	close(fd);

	return (count);
} */

int line_counter (char *filename)
{
	int fd;
	int count;
	char *buffer;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		write(1, "ERRO NO FD\n", 12);
		return (1);
	}

	buffer = get_next_line(fd);
	while(buffer)
	{
		count++;
		free(buffer);
		buffer = get_next_line(fd);
	}
	free(buffer);
	close(fd);

	return (count);
}

char ***parse_map (char *filename, int num_lines)
{
    int fd;
    int i;
	char *buffer;
    char ***lines;
/* 	char **split_buffer; */

    lines = (char ***)malloc(sizeof(char **) * num_lines);
    if (!lines)
    {
        ft_printf("LOG: ERRO NO MEMORIA\n");
        return (NULL);
    }

    i = 0;
    fd = open(filename, O_RDONLY);

    if (fd == -1)
    {
        ft_printf("LOG: ERRO NO FD\n");
        free(lines);
        return (NULL);
    }

	buffer = get_next_line(fd);
/* 	split_buffer = ft_split(buffer, ' '); */
    while (i < num_lines)
    {
        /* lines[i] = split_buffer; */
		lines[i] = ft_split(buffer, ' ');
        if (!lines[i])
        {
            printf("LOG: ERRO NO SPLIT");
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
        i++;
		free(buffer);
/* 		free(split_buffer); */
		buffer = get_next_line(fd);
/* 		split_buffer = ft_split(buffer, ' '); */
   }
	free(buffer);
/* 	free(split_buffer); */
    close(fd);
    return (lines);
}

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

	(void)orient;
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

/* void    drawline(t_mlx_data *data, char ***lines)
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

int handle_keysym(int keysym, t_main_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("\n[Evento]: Tecla ESC pressionada!\n Abortando...\n");
		mlx_destroy_image(data->mlx_data.mlx_ptr, data->mlx_data.img_ptr);
		mlx_destroy_window(data->mlx_data.mlx_ptr, data->mlx_data.win_ptr);
		mlx_destroy_display(data->mlx_data.mlx_ptr);
		free(data->mlx_data.mlx_ptr);
		/* ft_printf("[DEBUG]: %s\n", data->map_data.lines[3][3]); */
		free_lines(&data->map_data); //DESCOBRIR PQ NAO FUNCIONA
		exit(0);
	}

	return (0);
}

int	handle_tab(t_main_data *data)
{
	ft_printf("\n[EVENTO]: Usuario fechou a janela!");
	mlx_destroy_image(data->mlx_data.mlx_ptr, data->mlx_data.img_ptr);
	mlx_destroy_window(data->mlx_data.mlx_ptr, data->mlx_data.win_ptr);
	mlx_destroy_display(data->mlx_data.mlx_ptr);
	free(data->mlx_data.mlx_ptr);
	free_lines(&data->map_data); //DESCOBRIR PQ NAO FUNCIONA
	exit(0);
}

int main()
{
	t_main_data data;

	data.map_data.lines_count = line_counter("42.fdf");
	data.map_data.lines = parse_map("42.fdf", data.map_data.lines_count);

	write(1, data.map_data.lines[3][3], ft_strlen(data.map_data.lines[3][3]));



    /* t_mlx_data data; */
    data.mlx_data.mlx_ptr = mlx_init();
	if (data.mlx_data.mlx_ptr == 0)
	{
		printf("Erro ao iniciar!");
		return (1);
	}
    data.mlx_data.win_ptr = mlx_new_window(data.mlx_data.mlx_ptr, MAP_WIDTH * 10, MAP_HEIGHT * 10, "FDF - DMELO-CA");
    data.mlx_data.img_ptr = mlx_new_image(data.mlx_data.mlx_ptr, MAP_WIDTH * 10, MAP_HEIGHT * 10);
	mlx_hook(data.mlx_data.win_ptr, 2, 1L<<0, handle_keysym, &data);
	mlx_hook(data.mlx_data.win_ptr, 17, 0, handle_tab, &data);
	mlx_loop(data.mlx_data.mlx_ptr);

/*     drawline(&data, lines);
    mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);

    mlx_loop(data.mlx_ptr); */

    return 0;
}
