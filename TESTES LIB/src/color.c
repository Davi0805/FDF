/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 23:18:12 by davi              #+#    #+#             */
/*   Updated: 2024/11/22 02:08:49 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"

static int	color_range(int start_color, int end_color, double perc)
{
	t_rgb	start;
	t_rgb	end;
	t_rgb	res;

	if (perc < 0)
		perc = 0;
	if (perc > 1)
		perc = 1;
	start.r = (start_color >> 16) & 0xFF;
	start.g = (start_color >> 8) & 0xFF;
	start.b = start_color & 0xFF;
	end.r = (end_color >> 16) & 0xFF;
	end.g = (end_color >> 8) & 0xFF;
	end.b = end_color & 0xFF;
	res.r = (int)(start.r + perc * (end.r - start.r));
	res.g = (int)(start.g + perc * (end.g - start.g));
	res.b = (int)(start.b + perc * (end.b - start.b));
	return ((res.r << 16) | (res.g << 8) | res.b);
}

static int	zcolor(int z, int low, int high)
{
	double	perc;

	perc = (double)(z - low) / (high - low);
	return (color_range(RED_COLOR, WHITE_COLOR, perc));
}

void	set_zcolor(t_main_data *data)
{
	int	i;
	int	j;
	int	z;

	i = 0;
	while (i < data->map_data.lines_count)
	{
		j = 0;
		while (j < data->map_data.column_count)
		{
			z = data->coord_3d[i][j].z;
			if (data->coord_3d[i][j].color != -1)
				j = j;
			else if (data->map_data.z_max == data->map_data.z_min)
				data->coord_3d[i][j].color = 0xFF0000;
			else if (data->coord_3d[i][j].color == -1)
				data->coord_3d[i][j].color = zcolor(z, data->map_data.z_min,
						data->map_data.z_max);
			j++;
		}
		i++;
	}
}
