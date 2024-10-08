#include "minilibx-linux/mlx.h"
#include <stdlib.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define TILE_SIZE 20

typedef struct {
    void *mlx_ptr;
    void *win_ptr;
} t_data;

typedef struct s_map_data
{
	int **map;

} t_map_data;

int map[11][19] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

int get_color(int z)
{
	if(z == 0)
	{
		return 0xFF0000;
	}
	else if (z > 100)
	{
		return 0x0000FF;
	}
	else
	{
		int red = (z * 255) / 100;
		int blue = 255 - red;
		return (red << 16) | (blue);
	}
}


void draw_line(t_data *data, int x0, int y0, int x1, int y1, int color) {
    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);
    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;
    int err = dx - dy;

    while (1) {
        mlx_pixel_put(data->mlx_ptr, data->win_ptr, x0, y0, color);
        if (x0 == x1 && y0 == y1)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
		{
            err -= dy;
            x0 += sx;
        }
        if (e2 < dx)
		{
            err += dx;
            y0 += sy;
        }
    }
}

void isometric_projection(int x, int y, int z, int *new_x, int *new_y) {
    *new_x = (x - y) * cos(45);
    *new_y = (x + y) * cos(45) - z;
}

void draw_map(t_data *data) {
    int x;
	int y;
    int new_x1, new_y1, new_x2, new_y2;

	x = 0;
	y = 0;

    for (y = 0; y < 11; y++) {
        for (x = 0; x < 19; x++)
		{
            int z = map[y][x] * TILE_SIZE;

            if (x + 1 < 19) {
                isometric_projection(x * TILE_SIZE, y * TILE_SIZE, z, &new_x1, &new_y1);
                isometric_projection((x + 1) * TILE_SIZE, y * TILE_SIZE, map[y][x + 1] * TILE_SIZE, &new_x2, &new_y2);
                draw_line(data, new_x1 + WIDTH / 3, new_y1 + HEIGHT / 3, new_x2 + WIDTH / 3, new_y2 + HEIGHT / 3, get_color(z));
            }

            if (y + 1 < 11) {
                isometric_projection(x * TILE_SIZE, y * TILE_SIZE, z, &new_x1, &new_y1);
                isometric_projection(x * TILE_SIZE, (y + 1) * TILE_SIZE, map[y + 1][x] * TILE_SIZE, &new_x2, &new_y2);
                draw_line(data, new_x1 + WIDTH / 3, new_y1 + HEIGHT / 3, new_x2 + WIDTH / 3, new_y2 + HEIGHT / 3, get_color(z));
            }
        }
    }
}

int main() {
    t_data data;

    data.mlx_ptr = mlx_init();
    data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "FDF");

    draw_map(&data);


    mlx_loop(data.mlx_ptr);

    return 0;
}
