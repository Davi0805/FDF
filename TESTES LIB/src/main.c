/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:10:31 by davi              #+#    #+#             */
/*   Updated: 2024/11/22 01:56:14 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"

void	initialize_mlx_data(t_mlx_data *mlx_data)
{
	if (mlx_data != NULL)
	{
		mlx_data->mlx_ptr = NULL;
		mlx_data->win_ptr = NULL;
		mlx_data->img_ptr = NULL;
	}
}

t_main_data	*initialize_main_data(void)
{
	t_main_data	*data;

	data = (t_main_data *)malloc(sizeof(t_main_data));
	if (data == NULL)
		return (NULL);
	data->mlx_data = (t_mlx_data *)malloc(sizeof(t_mlx_data));
	if (data->mlx_data == NULL)
	{
		free(data);
		return (NULL);
	}
	initialize_mlx_data(data->mlx_data);
	return (data);
}

int	window_init(t_main_data *data)
{
	data->mlx_data->mlx_ptr = mlx_init();
	if (!data->mlx_data->mlx_ptr)
		ft_mlx_failed(data);
	data->mlx_data->win_ptr = mlx_new_window(data->mlx_data->mlx_ptr,
			WIDTH, HEIGHT, "FDF - dmelo-ca");
	if (!data->mlx_data->win_ptr)
		ft_mlx_failed(data);
	data->mlx_data->img_ptr = mlx_new_image(data->mlx_data->mlx_ptr,
			WIDTH, HEIGHT);
	if (!data->mlx_data->img_ptr)
		ft_mlx_failed(data);
	data->mlx_data->img_addr = mlx_get_data_addr(data->mlx_data->img_ptr,
			&data->mlx_data->bits_per_pixel,
			&data->mlx_data->size_line, &data->mlx_data->endian);
	if (!data->mlx_data->img_addr)
		ft_mlx_failed(data);
	mlx_key_hook(data->mlx_data->win_ptr, input_handle, data);
	mlx_hook(data->mlx_data->win_ptr, 17, 0, ft_program_kill, data);
	return (1);
}

int	main(int ac, char **av)
{
	t_main_data	*data;

	if (!parse_error(ac, av))
		return (1);
	data = initialize_main_data();
	if (!data)
		return (1);
	if (!window_init(data))
		return (1);
	map_size(av[1], data);
	init_map(data);
	allocate_3d(data);
	allocate_projec(data);
	data->map_data.padding = get_smaller(WIDTH / data->map_data.column_count,
			HEIGHT / data->map_data.lines_count) / 2;
	data->map_data.padding = get_bigger(2, data->map_data.padding);
	get_map_lines(data, av[1]);
	set_zcolor(data);
	build_image(data);
	mlx_put_image_to_window(data->mlx_data->mlx_ptr, data->mlx_data->win_ptr,
		data->mlx_data->img_ptr, 0, 0);
	mlx_loop(data->mlx_data->mlx_ptr);
}
