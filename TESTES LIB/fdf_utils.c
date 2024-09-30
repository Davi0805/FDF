/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmelo-ca <dmelo-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 13:49:22 by dmelo-ca          #+#    #+#             */
/*   Updated: 2024/09/30 15:47:56 by dmelo-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data_structs.h"
#include <stdlib.h>

int free_lines(t_map_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(i < data->lines_count)
	{
		while(data->lines[i][j])
		{
			free(data->lines[i][j]);
			j++;
		}
		free(data->lines[i]);
		i++;
	};
	free(data->lines);
	return (0);
};
