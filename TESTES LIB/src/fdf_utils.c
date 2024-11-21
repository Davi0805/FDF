/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:49:22 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/21 00:23:45 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"

int ft_program_kill(t_main_data *data)
{
    mlx_destroy_window(data->mlx_data->mlx_ptr, data->mlx_data->win_ptr);
    mlx_destroy_image(data->mlx_data->mlx_ptr, data->mlx_data->img_ptr);
	mlx_destroy_display(data->mlx_data->mlx_ptr);
	free(data->mlx_data->mlx_ptr);
    free(data->mlx_data);
    free_3d(data);
    free_2d(data);
    free(data);
    exit(0);
}

int	get_bigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_smaller(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

void free_3d(t_main_data *data)
{
    int i;

    i = 0;
    while (i < data->map_data.lines_count)
    {
        if (data->coord_3d[i])
            free(data->coord_3d[i]);
        i++;
    }
    if (data->coord_3d)
        free(data->coord_3d);
}

void	ft_free_split(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}


