/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_logic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 00:49:57 by davi              #+#    #+#             */
/*   Updated: 2024/11/22 01:56:47 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include <math.h>

void	put_pixel_to_img(t_mlx_data *mlx_data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < WIDTH && y < HEIGHT)
	{
		dst = mlx_data->img_addr + (y * mlx_data->size_line + x
				* (mlx_data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_isometric_projection(t_main_data *data, int i, int j)
{
	t_projec	*new;
	t_3d_coord	*prev;
	t_3d_coord	tmp;

	prev = &(data->coord_3d[i][j]);
	new = &(data->projec[i][j]);
	tmp.y = prev->y;
	tmp.x = prev->x;
	tmp.z = prev->z * data->map_data.scale;
	tmp.color = prev->color;
	new->color = prev->color;
	new->y = (-tmp.z * data->map_data.cam_zoom
			+ (tmp.x * data->map_data.cam_zoom
				+ tmp.y * data->map_data.cam_zoom)
			* data->map_data.sin_beta + data->map_data.y_offset);
	new->x = ((tmp.x * data->map_data.cam_zoom - tmp.y
				* data->map_data.cam_zoom)
			* data->map_data.cos_alpha
			+ data->map_data.x_offset);
}

void	bresenham(t_main_data *data, t_projec a, t_projec b)
{
	int			err[2];
	t_projec	cur;

	cur.y = a.y;
	cur.x = a.x;
	cur.color = a.color;
	err[0] = abs(b.x - a.x) - abs(b.y - a.y);
	while (cur.x != b.x || cur.y != b.y)
	{
		if ((unsigned int)cur.x < WIDTH && (unsigned int)cur.y < HEIGHT)
			put_pixel_to_img(data->mlx_data, cur.x, cur.y, cur.color);
		err[1] = 2 * err[0];
		if (err[1] > -abs(b.y - a.y))
		{
			err[0] -= abs(b.y - a.y);
			cur.x += (a.x < b.x);
			cur.x -= (b.x < a.x);
		}
		if (err[1] < abs(b.x - a.x))
		{
			err[0] += abs(b.x - a.x);
			cur.y += (a.y < b.y);
			cur.y -= (b.y < a.y);
		}
	}
}

void	ft_draw_line(t_main_data *data, int x, int y)
{
	if (y == 0 && x == 0)
		ft_isometric_projection(data, y, x);
	if (y + 1 < data->map_data.lines_count)
	{
		ft_isometric_projection(data, y + 1, x);
		bresenham(data, data->projec[y][x],
			data->projec[y + 1][x]);
	}
	if (x + 1 < data->map_data.column_count)
	{
		if (y == 0)
			ft_isometric_projection(data, y, x + 1);
		bresenham(data, data->projec[y][x],
			data->projec[y][x + 1]);
	}
}

void	build_image(t_main_data *data)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->map_data.lines_count)
	{
		j = -1;
		while (++j < data->map_data.column_count)
			ft_draw_line(data, j, i);
	}
}
