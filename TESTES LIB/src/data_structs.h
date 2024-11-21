/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:23:12 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/21 00:45:44 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
#define	FDF_H

#include <X11/keysym.h>
#include "../minilibx-linux/mlx.h"
#include "../Libft/get_next_line/get_next_line.h"
#include "../Libft/ft_printf.h"
#include <fcntl.h>
#include <stdio.h>
#include <math.h>

#define WIDTH 1280
#define HEIGHT 720

typedef struct	s_map_data
{
	int		lines_count;
    int		column_count;
    double  alpha;
    double  beta;
    double  sin_beta;
    double  cos_alpha;
    double     cam_zoom;
    int  z_max;
    int  z_min;
    double  x_offset;
    double  y_offset;
    double  padding;
    int  scale;
}				t_map_data;

typedef struct s_3d_coord
{
    int x;
    int y;
    int z;
}               t_3d_coord;

typedef struct s_2d_coord
{
    int x;
    int y;
    int z;
}               t_2d_coord;

typedef struct s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    void    *img_ptr;
    void    *img_addr;
    int     bits_per_pixel;
    int     size_line;
    int     endian;
}   t_mlx_data;

typedef struct s_main_data
{
	t_mlx_data	*mlx_data;
	t_map_data	map_data;
	t_3d_coord		**coord_3d;
    t_2d_coord      **coord_2d;
}				t_main_data;


int     parse_error(int ac, char **av);
int     window_init(t_main_data *data);
void initialize_mlx_data(t_mlx_data *mlx_data);
t_main_data *initialize_main_data();
void map_size(char *filename, t_main_data *data);
void	init_map(t_main_data *data);

int	get_bigger(int a, int b);
int	get_smaller(int a, int b);
int ft_program_kill(t_main_data *data);
void free_3d(t_main_data *data);
void	ft_free_split(char **array);
void free_2d(t_main_data *data);

void allocate_3d(t_main_data *data);
void allocate_2d(t_main_data *data);

void    get_map_lines(t_main_data *data, char *filepath);

void	put_pixel_to_img(t_mlx_data *mlx_data, int x, int y, int color);

void	build_image(t_main_data *data);

#endif
