#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

// gcc image.c -Lminilibx-linux -lmlx_Linux -lX11 -lXext

#define MALLOC_ERROR	1
#define WIDTH			1000
#define HEIGHT			1000
#define SIDE_LEN        (WIDTH + HEIGHT)

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct  s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
}               t_mlx_data;

typedef struct s_coord
{
	int x;
	int	y;
	int z;
}				t_coord;

typedef struct s_decis
{
	int	decis1;
	int	decis2;
}				t_decis;

void appendpoint(t_coord point, t_coord points[100], int* points_index)
{
    points[*points_index] = point;
    (*points_index)++;
}


t_coord	*bresenhamn(t_coord *source, t_coord *destination, t_coord points[100], int* points_index)
{
	t_coord d;
	t_coord step;
	t_coord current;
	t_decis decis;


	d.x = ((destination->x) -  (source->x));
	d.y = ((destination->y) -  (source->y));
	d.z = ((destination->z) -  (source->z));

	if (destination->x >= source->x)
		step.x = 1;
	else
		step.x = -1;
	if (destination->y >= source->y)
		step.y = 1;
	else
		step.y = -1;
	if (destination->z >= source->z)
		step.z = 1;
	else
		step.z = -1;

	if (destination->x >= destination->y && destination->x >= destination->z)
	{
		decis.decis1 = (2 * destination->y - destination->x);
		decis.decis2 = (2 * destination->z - destination->x);
	}
	else if (destination->y >= destination->x && destination->y >= destination->z)
	{
		decis.decis1 = (2 * destination->x - destination->y);
		decis.decis2 = (2 * destination->z - destination->y);
	}
	else
	{
		decis.decis1 = (2 * destination->y - destination->z);
		decis.decis2 = (2 * destination->x - destination->z);
	}
    current = *source;

    appendpoint(current, points, points_index);

	if (destination->x >= destination->y && destination->x >= destination->z)
	{
		while (current.x != destination->x)
		{
			if (decis.decis1 >= 0)
			{
				current.y += step.y;
				decis.decis1 -= 2 * destination->x;
			}
			if (decis.decis2 >= 0)
			{
				current.z += step.z;
				decis.decis2 -= 2 * destination->x;
			}
			decis.decis1 += 2 * destination->y;
			decis.decis2 += 2 * destination->z;
			current.x += step.x;
			appendpoint(current, points, points_index);
		}
	}
	else if (destination->y >= destination->z && destination->y >= destination->z)
	{
		while (current.y != destination->y)
		{
			if (decis.decis1 >= 0)
			{
				current.x += step.x;
				decis.decis1 -= 2 * destination->y;
			}
			if (decis.decis2 >= 0)
			{
				current.z += step.z;
				decis.decis2 -= 2 * destination->y;
			}
			decis.decis1 += 2 * destination->x;
			decis.decis2 += 2 * destination->z;
			current.y += step.y;
			appendpoint(current, points, points_index);
		}
	}
	else
	{
		while (current.z != destination->z)
		{
			if (decis.decis1 >= 0)
			{
				current.y += step.y;
				decis.decis1 -= 2 * destination->z;
			}
			if (decis.decis2 >= 0)
			{
				current.x += step.x;
				decis.decis2 -= 2 * destination->z;
			}
			decis.decis1 += 2 * destination->y;
			decis.decis2 += 2 * destination->x;
			current.z += step.z;
			appendpoint(current, points, points_index);
		}
	}

	appendpoint(current, points, points_index);

	return points;
}

void	my_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	int	offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (data->img.line_len * y) + (x * (data->img.bits_per_pixel / 8));

	*((unsigned int *)(offset + data->img.img_pixels_ptr)) = color;
}

/* void	drawsquare(t_mlx_data *data, int x_pos, int color)
{
	static int count;

	count++;
	if (count == 1)
	{
	my_pixel_put(&data->img, x_pos * 5, 5, color);
	my_pixel_put(&data->img, x_pos * 20, 5, color);
	my_pixel_put(&data->img, x_pos * 5, 20, color);
	my_pixel_put(&data->img, x_pos * 20, 20, color);
	return ;
	}
	my_pixel_put(&data->img, x_pos * 20, 5, color);
	my_pixel_put(&data->img, x_pos * 20, 20, color);
} */

void	drawline(t_mlx_data *data, t_coord *source, t_coord *destination, int color, int orient)
{
	t_coord points[100];
    int points_index = 0;
	int i;

	i = 0;

	bresenhamn(source, destination, points, &points_index);

	if (orient == 1)
	{
		while (i++ < points_index)
			my_pixel_put(data, points[i].x, points[i].y, color);
	}
	else
	{
		while (i++ < points_index)
			my_pixel_put(data, points[i].x, points[i].y, color);
	}
}

/* void	drawgrid(t_mlx_data *data, int	width, int height, int color)
{
	int	i = 0;
	int scale = width / 20;
	int	x_point = 1;
	int	y_point = 1;

	while (i < scale)
	{
		drawline(data, 1, x_point, WIDTH, 1, color, 1);
		x_point += 20;
		i++;
	}
	i = 0;
	while(i < scale)
	{
		drawline(data, y_point, 1, 1, HEIGHT, color, 2);
		y_point += 20;
		i++;
	}
} */

int input_handle(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape)
    {
        printf("Tecla Esc pressionada, abortando processo!");
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
	/* if (keysym == XK_b)
    {
        printf("Tecla B pressionada!");
		drawgrid(data, WIDTH, HEIGHT, 0x0000FF);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
    }
	if (keysym == XK_g)
    {
        printf("Tecla G pressionada!");
		drawgrid(data, WIDTH, HEIGHT, 0x00ff00);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
    }
	if (keysym == XK_r)
    {
        printf("Tecla R pressionada!");
		drawgrid(data, WIDTH, HEIGHT, 0x00FF0000);
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
    } */
    return (0);
}

/* int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	drawsquare(&img, 1, 0x00FF0000);
	drawsquare(&img, 2, 0x00FF0000);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_key_hook(mlx_win, input_handle, &data);
	mlx_loop(mlx);
} */

int	main()
{
    t_mlx_data  data;
	t_coord inicio;
    t_coord fim;

    inicio.x = 2;
    inicio.y = 2;
    inicio.z = 2;

    fim.x = 10;
    fim.y = 5;
    fim.z = 7;

    int points_index = 0;
    t_coord points[100];

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MALLOC_ERROR);

	data.win_ptr = mlx_new_window(data.mlx_ptr,
								HEIGHT,
								WIDTH,
								"FDF");
	if (data.win_ptr == NULL)
    {
        mlx_destroy_display(data.mlx_ptr); // Cleanup MLX connection
        free(data.mlx_ptr);
        return (MALLOC_ERROR);
    }

    data.img.img_ptr = mlx_new_image(data.mlx_ptr,
                                    SIDE_LEN,
                                    SIDE_LEN);

    data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr,
                                                &data.img.bits_per_pixel,
                                                &data.img.line_len,
                                                &data.img.endian);

/* 	drawgrid(&data, WIDTH, HEIGHT, 0x00FF0000); */
	drawline(&data, &inicio, &fim, 0x00FF0000, 1);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
    //KEY INPUTS
    mlx_key_hook(data.win_ptr,
                input_handle,
                &data);
    //WINDOW LOOP
	mlx_loop(data.mlx_ptr);
}
