#include "data_structs.h"

void free_2d(t_main_data *data)
{
    int i;

    i = 0;
    while (i < data->map_data.lines_count)
    {
        if (data->coord_2d[i])
            free(data->coord_2d[i]);
        i++;
    }
    if (data->coord_2d)
        free(data->coord_2d);
}

int     parse_error(int ac, char **av)
{
    int fd;

    fd = 0;
    if (ac != 2)
    {
        ft_printf("[ERROR]: Wrong number of arguments!\n");
        return (0);
    }
    if (ft_strlen(av[1]) <= 4 || ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".fdf", 4))
    {
        ft_printf("[ERROR]: Wrong number of arguments!\n");
        return (0);
    }
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Failed to open this file!\n");
        return(0);
    }
    else
        close(fd);
    return (1);
}

int input_handle(int keysym, t_main_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_printf("Tecla Esc pressionada, abortando processo!\n");
        ft_program_kill(data);
		exit(1);
	}
    else if (keysym == XK_Right)
        data->map_data.x_offset -= 10;
    else if (keysym == XK_Left)
        data->map_data.x_offset += 10;
    else if (keysym == XK_Down)
        data->map_data.y_offset -= 10;
    else if (keysym == XK_Up)
        data->map_data.y_offset += 10;
    else if (keysym == XK_KP_Add || keysym == XK_plus)
        data->map_data.cam_zoom += 0.1;
    else if (keysym == XK_KP_Subtract || keysym == XK_minus)
        data->map_data.cam_zoom -= 0.1;
    mlx_destroy_image(data->mlx_data->mlx_ptr, data->mlx_data->img_ptr);
    data->mlx_data->img_ptr = mlx_new_image(data->mlx_data->mlx_ptr, WIDTH, HEIGHT);
    data->mlx_data->img_addr = mlx_get_data_addr(data->mlx_data->img_ptr, &data->mlx_data->bits_per_pixel, &data->mlx_data->size_line, &data->mlx_data->endian);
    build_image(data);
    mlx_put_image_to_window(data->mlx_data->mlx_ptr, data->mlx_data->win_ptr, data->mlx_data->img_ptr, 0,
		0);
	return (0);
}

int     window_init(t_main_data *data)
{
    data->mlx_data->mlx_ptr = mlx_init();
    if (!data->mlx_data->mlx_ptr)
    {
        ft_printf("[ERRO]: X11 failed to create the window!\n");
        return (0);
    }
    data->mlx_data->win_ptr = mlx_new_window(data->mlx_data->mlx_ptr, WIDTH, HEIGHT, "FDF - dmelo-ca");
    if (!data->mlx_data->win_ptr)
    {
        ft_printf("[ERRO]: X11 failed to create the window!\n");
        return (0);
    }
    data->mlx_data->img_ptr = mlx_new_image(data->mlx_data->mlx_ptr, WIDTH, HEIGHT);
    if (!data->mlx_data->img_ptr)
    {
        ft_printf("[ERRO]: X11 failed to create the image!\n");
        return (0);
    }
    data->mlx_data->img_addr = mlx_get_data_addr(data->mlx_data->img_ptr, &data->mlx_data->bits_per_pixel,
        &data->mlx_data->size_line, &data->mlx_data->endian);
    if (!data->mlx_data->img_addr)
    {
        ft_printf("[ERRO]: X11 failed to setup image!\n");
        return (0);
    }
    mlx_key_hook(data->mlx_data->win_ptr, input_handle, data);
    mlx_hook(data->mlx_data->win_ptr, 17, 0, ft_program_kill, data);
    return (1);
}

void	put_pixel_to_img(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = mlx_data->img_addr + (y * mlx_data->size_line + x * (mlx_data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
