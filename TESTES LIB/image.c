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

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	drawsquare(t_mlx_data *data, int x_pos, int color)
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
}

void	drawline(t_mlx_data *data, int x_startpos, int y_startpos, int x_endpos, int y_endpos, int color, int orient)
{
	while (x_startpos < x_endpos && orient == 1)
	{
		my_pixel_put(&data->img, x_startpos, y_startpos, color);
		x_startpos++;
	}
	while (y_startpos < y_endpos && orient == 2)
	{
		my_pixel_put(&data->img, x_startpos, y_startpos, color);
		y_startpos++;
	}
}

void	drawgrid(t_mlx_data *data, int	width, int height, int color)
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
}

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
	if (keysym == XK_b)
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
    }
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
/* 	drawsquare(&data, 1, 0x00FF0000);
	drawsquare(&data, 2, 0x00FF0000);
	drawsquare(&data, 3, 0x00FF0000);
	drawsquare(&data, 4, 0x00FF0000);
	drawsquare(&data, 5, 0x00FF0000);
	drawsquare(&data, 6, 0x00FF0000);
	drawsquare(&data, 7, 0x00FF0000);
	drawsquare(&data, 8, 0x00FF0000);
	drawsquare(&data, 9, 0x00FF0000);
	drawsquare(&data, 10, 0x00FF0000);
	drawsquare(&data, 11, 0x00FF0000);
	drawsquare(&data, 12, 0x00FF0000);
	drawsquare(&data, 13, 0x00FF0000);
	drawsquare(&data, 14, 0x00FF0000);
	drawsquare(&data, 15, 0x00FF0000);
	drawsquare(&data, 16, 0x00FF0000);
	drawsquare(&data, 17, 0x00FF0000);
	drawsquare(&data, 18, 0x00FF0000);
	drawsquare(&data, 19, 0x00FF0000);
	drawsquare(&data, 20, 0x00FF0000); */
	//drawline(&data, 1, 1, WIDTH, 1, 0x00FF0000);
	//drawline(&data, 1, (HEIGHT - 1), WIDTH, 1, 0x00FF0000);
	drawgrid(&data, WIDTH, HEIGHT, 0x00FF0000);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.img_ptr, 0, 0);
    //KEY INPUTS
    mlx_key_hook(data.win_ptr,
                input_handle,
                &data);
    //WINDOW LOOP
	mlx_loop(data.mlx_ptr);
}
