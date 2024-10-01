/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:23:12 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/10/01 16:01:02 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
#define	FDF_H

typedef struct	s_map_data
{
	char	***lines;
	int		lines_count;
}				t_map_data;

typedef struct s_coord
{
    int x;
    int y;
    int z;
}   t_coord;

typedef struct s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
}   t_mlx_data;

typedef struct s_main_data
{
	t_mlx_data	mlx_data;
	t_map_data	map_data;
	t_coord		coords_data;
}				t_main_data;


#endif
