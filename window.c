#include "minilibx-linux/mlx.h"
#include <X11/keysym.h>
#include <stdio.h>
#include <stdlib.h>

#define MALLOC_ERROR	1
#define WIDTH			400
#define HEIGHT			400
#define SIDE_LEN        800

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_img;

typedef struct  s_mlx_data
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   img;
}               t_mlx_data;

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	//🚨 Line len is in bytes. WIDTH 800 len_line ~3200 (can differ for alignment)
	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));	

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

/*
 * 🔥 my_pixel_put
*/
void	color_screen(t_mlx_data *data, int color)
{
	for (int y = 0; y < SIDE_LEN; ++y)	
	{
		for (int x = 0; x < SIDE_LEN; ++x)
		{
			/*
			 * This function is much faster than the library one🏻
			 * 	~Buffer in the image and push only when ready-> No flickering effect
			*/
			my_pixel_put(&data->img,
						x, 
						y, 
						color);
		}
	}
}

/*
 * This time i plug color in hexadecimal directly
 * easy vanilla
*/
int	color_handle(int keysym, t_mlx_data *data)
{

	if (keysym == XK_r)
	{
        color_screen(data, 0xff0000);
	}
	else if (keysym == XK_g)
	{
		color_screen(data, 0xff00);
	}
	else if (keysym == XK_b)
	{
		color_screen(data, 0xff);
	}	
	else if (keysym == XK_Escape)
		exit(1);

	// push the READY image to window
	// the last parameters are the offset image-window
	mlx_put_image_to_window(data->mlx_ptr,
							data->win_ptr, 
							data->img.img_ptr, 
							0, 0);

	return 0;
}

int input_handle(int keysym, t_mlx_data *data)
{
    if (keysym == XK_Escape)
    {
        printf("Tecla Esc pressionada, abortando processo!");
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(1);
    }
    printf("Tecla %d pressionada!\n", keysym);
    return (0);
}

int	main()
{
    t_mlx_data  data;

	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		return (MALLOC_ERROR);

	data.win_ptr = mlx_new_window(data.mlx_ptr,
								HEIGHT,
								WIDTH,
								"FDF");
	if (data.win_ptr == NULL)
    {
        mlx_destroy_display(data.mlx_ptr); // Cleanup MLX connection
        free(data.mlx_ptr);
        return (MALLOC_ERROR);
    }

    data.img.img_ptr = mlx_new_image(data.mlx_ptr,
                                    SIDE_LEN,
                                    SIDE_LEN);

    data.img.img_pixels_ptr = mlx_get_data_addr(data.img.img_ptr, 
                                                &data.img.bits_per_pixel,
                                                &data.img.line_len,
                                                &data.img.endian);

    	printf("Line_len %d <-> SIDE_LEN %d\n"
			"bpp %d\n"
			"endian %d\n", data.img.line_len, SIDE_LEN, data.img.bits_per_pixel, data.img.endian);

    //KEY INPUTS
    mlx_key_hook(data.win_ptr, 
                color_handle, 
                &data);
    //WINDOW LOOP
	mlx_loop(data.mlx_ptr); 
}