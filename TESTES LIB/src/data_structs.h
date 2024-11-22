/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davi <davi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:23:12 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/11/22 02:07:36 by davi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_STRUCTS_H
# define DATA_STRUCTS_H

# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../Libft/get_next_line/get_next_line.h"
# include "../Libft/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define RED_COLOR 0xFF0000
# define WHITE_COLOR 0xFFFFFF
# define WIDTH 1920
# define HEIGHT 1080
# define BASE_16 "0123456789abcdef"
# ifndef M_PI
#  define M_PI 3.14159
# endif

typedef struct s_map_data
{
	int		lines_count;
	int		column_count;
	double	alpha;
	double	beta;
	double	sin_beta;
	double	cos_alpha;
	double	cam_zoom;
	int		z_max;
	int		z_min;
	double	x_offset;
	double	y_offset;
	double	padding;
	int		scale;
}				t_map_data;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct s_3d_coord
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_3d_coord;

typedef struct s_projec
{
	int	x;
	int	y;
	int	color;
}				t_projec;

typedef struct s_mlx_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*img_addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}				t_mlx_data;

typedef struct s_main_data
{
	t_mlx_data	*mlx_data;
	t_map_data	map_data;
	t_3d_coord	**coord_3d;
	t_projec	**projec;
}				t_main_data;

// INIT
int			window_init(t_main_data *data);
void		initialize_mlx_data(t_mlx_data *mlx_data);
t_main_data	*initialize_main_data(void);
void		init_map(t_main_data *data);
void		allocate_3d(t_main_data *data);
void		allocate_projec(t_main_data *data);
// UTILS
int			get_bigger(int a, int b);
int			get_smaller(int a, int b);
int			ft_program_kill(t_main_data *data);
void		free_3d(t_main_data *data);
void		ft_free_split(char **array);
void		ft_mlx_failed(t_main_data *data);
void		free_projec(t_main_data *data);
int			input_handle(int keysym, t_main_data *data);
// PARSE
int			parse_error(int ac, char **av);
void		map_size(char *filename, t_main_data *data);
void		get_map_lines(t_main_data *data, char *filepath);
void		set_zcolor(t_main_data *data);
// DRAW
void		put_pixel_to_img(t_mlx_data *mlx_data, int x, int y, int color);
void		build_image(t_main_data *data);

#endif
