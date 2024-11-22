/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:05:19 by davi              #+#    #+#             */
/*   Updated: 2024/11/22 01:49:29 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"

void	free_projec(t_main_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_data.lines_count)
	{
		if (data->projec[i])
			free(data->projec[i]);
		i++;
	}
	if (data->projec)
		free(data->projec);
}

int	parse_error(int ac, char **av)
{
	int	fd;

	fd = 0;
	if (ac != 2)
	{
		ft_printf("[ERROR]: Wrong number of arguments!\n");
		return (0);
	}
	if (ft_strlen(av[1]) <= 4 || ft_strncmp(&av[1][ft_strlen(av[1]) - 4]
		, ".fdf", 4))
	{
		ft_printf("[ERROR]: Wrong number of arguments!\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Failed to open this file!\n");
		return (0);
	}
	else
		close(fd);
	return (1);
}

void	ft_keysym(t_main_data *data, int keysym)
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
}

int	input_handle(int keysym, t_main_data *data)
{
	ft_keysym(data, keysym);
	mlx_destroy_image(data->mlx_data->mlx_ptr, data->mlx_data->img_ptr);
	data->mlx_data->img_ptr = mlx_new_image(data->mlx_data->mlx_ptr,
			WIDTH, HEIGHT);
	data->mlx_data->img_addr = mlx_get_data_addr(data->mlx_data->img_ptr,
			&data->mlx_data->bits_per_pixel,
			&data->mlx_data->size_line, &data->mlx_data->endian);
	build_image(data);
	mlx_put_image_to_window(data->mlx_data->mlx_ptr,
		data->mlx_data->win_ptr, data->mlx_data->img_ptr, 0,
		0);
	return (0);
}

void	ft_mlx_failed(t_main_data *data)
{
	if (!data->mlx_data->win_ptr)
		mlx_destroy_window(data->mlx_data->mlx_ptr, data->mlx_data->win_ptr);
	if (!data->mlx_data->img_ptr)
		mlx_destroy_image(data->mlx_data->mlx_ptr, data->mlx_data->img_ptr);
	if (!data->mlx_data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_data->mlx_ptr);
		free(data->mlx_data->mlx_ptr);
	}
	free(data->mlx_data);
	free(data);
	exit(1);
}
