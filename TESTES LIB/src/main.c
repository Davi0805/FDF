/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 00:10:31 by davi              #+#    #+#             */
/*   Updated: 2024/11/21 00:45:44 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"

void initialize_mlx_data(t_mlx_data *mlx_data)
{
    if (mlx_data != NULL)
    {
        mlx_data->mlx_ptr = NULL;
        mlx_data->win_ptr = NULL;
        mlx_data->img_ptr = NULL;
    }
}

t_main_data *initialize_main_data()
{
    t_main_data *data;

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

int main(int ac, char **av)
{
    t_main_data *data;

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
    allocate_2d(data);
    data->map_data.padding = get_smaller(WIDTH / data->map_data.column_count, HEIGHT / data->map_data.lines_count) / 2;
	data->map_data.padding = get_bigger(2, data->map_data.padding);
    get_map_lines(data, av[1]);
    build_image(data);
    mlx_put_image_to_window(data->mlx_data->mlx_ptr, data->mlx_data->win_ptr, data->mlx_data->img_ptr, 0,
		0);
    mlx_loop(data->mlx_data->mlx_ptr);
}
