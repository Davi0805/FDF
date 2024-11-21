#include "data_structs.h"

void allocate_3d(t_main_data *data)
{
    int i;

    i = 0;
    data->coord_3d = malloc(sizeof(t_3d_coord *) * (data->map_data.lines_count));
    if (!data->coord_3d)
        ft_printf("Alocacao de y falhou!\n");
    while (i < data->map_data.lines_count)
    {
        data->coord_3d[i] = malloc(sizeof(t_3d_coord) * (data->map_data.column_count));
        if (!data->coord_3d[i])
            ft_printf("Alocacao de x falhou!\n");
        i++;
    }
    ft_printf("Alocacao concluida!\n");
}

void allocate_2d(t_main_data *data)
{
    int i;

    i = 0;
    data->coord_2d = malloc(sizeof(t_2d_coord *) * (data->map_data.lines_count));
    if (!data->coord_2d)
        ft_printf("Alocacao de y falhou!\n");
    while (i < data->map_data.lines_count)
    {
        data->coord_2d[i] = malloc(sizeof(t_2d_coord) * (data->map_data.column_count));
        if (!data->coord_2d[i])
            ft_printf("Alocacao de x falhou!\n");
        i++;
    }
    ft_printf("Alocacao concluida!\n");
}

void    populate_3d(t_main_data *data, int i, char **str)
{
    int j;

    j = 0;
    while (j < data->map_data.column_count)
    {
        data->map_data.x_offset = (data->map_data.column_count - 1) * data->map_data.padding / 10;
	    data->map_data.y_offset = (data->map_data.lines_count - 1) * data->map_data.padding / 2;
        data->coord_3d[i][j].y = i * data->map_data.padding - data->map_data.y_offset;
        data->coord_3d[i][j].x = j * data->map_data.padding - data->map_data.x_offset;
        data->coord_3d[i][j].z = ft_atoi(str[j]) * data->map_data.padding;
        data->map_data.z_max = get_bigger(data->map_data.z_max, data->coord_3d[i][j].z);
		data->map_data.z_min = get_smaller(data->map_data.z_min, data->coord_3d[i][j].z);
        j++;
    }
}

void    get_map_lines(t_main_data *data, char *filepath)
{
    int fd;
    char *str;
    char **str_array;
    int  i;

    i = 0;
    fd = open(filepath, O_RDONLY);
    if (fd < 0)
        ft_printf("Erro no FD ao preencher mapa!\n");
    while (i < data->map_data.lines_count)
    {
        str = get_next_line(fd);
        str_array = ft_split(str, ' ');
        populate_3d(data, i, str_array);
        free(str);
        ft_free_split(str_array);
        i++;
    }
    close(fd);  
}

void	init_map(t_main_data *data)
{
	data->map_data.alpha = 0.46373398 / 2;
	data->map_data.beta = 0.46373398;
	data->map_data.x_offset = WIDTH / 2;
	data->map_data.y_offset = HEIGHT / 2;
	data->map_data.cam_zoom = 1;
	data->map_data.scale = 1;
    data->map_data.z_max = 0;
    data->map_data.z_min = 0;
    data->map_data.cos_alpha = cos(data->map_data.alpha);
    data->map_data.sin_beta = sin(data->map_data.beta);
}