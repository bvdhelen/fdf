/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   centered.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:14:36 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/08/06 10:14:36 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/* ERA PARA CALCULAR EL NUMERO DE PASOS DEL GRADIENTE DE COLOR
void	calculate_z_range(t_fdf *data, int *range_min, int *range_max)
{
	int	x;
	int	y;

	*range_min = data->z_matrix[0][0];
	*range_max = data->z_matrix[0][0];
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->z_matrix[y][x] < *range_min)
				*range_min = data->z_matrix[y][x];
			if (data->z_matrix[y][x] > *range_max)
				*range_max = data->z_matrix[y][x];
			x++;
		}
		y++;
	}
}
*/
/*Función que aplica la proyección adecuada al punto (x, y)
según el modo de proyección*/
void	project_point(float *x, float *y, int z, t_fdf *data)
{
	if (data->projection_mode == PROJ_ISOMETRIC)
		isometric(x, y, z, data);
	else if (data->projection_mode == PROJ_PLANTA)
		proj_planta(x, y, z, data);
	else if (data->projection_mode == PROJ_ALZADO)
		proj_alzado(x, y, z, data);
	else if (data->projection_mode == PROJ_PERFIL)
		proj_perfil(x, y, z, data);
}

/*Función que actualiza los valores mínimo y máximo de la bounding box
con las coordenadas proyectadas*/
void	update_bounding_box(t_bbox *bbox, float proj_x, float proj_y)
{
	if (proj_x < bbox->min_x)
		bbox->min_x = proj_x;
	if (proj_x > bbox->max_x)
		bbox->max_x = proj_x;
	if (proj_y < bbox->min_y)
		bbox->min_y = proj_y;
	if (proj_y > bbox->max_y)
		bbox->max_y = proj_y;
}

/*Función que calcula la bounding box proyectando todos los puntos de la matriz
según el modo de proyección*/
void	calculate_bounding_box(t_fdf *data, t_bbox *bbox)
{
	int		x;
	int		y;
	float	proj_x;
	float	proj_y;

	bbox->min_x = FLOAT_MAX;
	bbox->max_x = FLOAT_MIN;
	bbox->min_y = FLOAT_MAX;
	bbox->max_y = FLOAT_MIN;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			proj_x = x * data->zoom;
			proj_y = y * data->zoom;
			project_point(&proj_x, &proj_y, data->z_matrix[y][x], data);
			update_bounding_box(bbox, proj_x, proj_y);
			x++;
		}
		y++;
	}
}

/*Función que calcula el centro del mapa en pantalla,
a partir de la bounding box*/
void	calculate_center(t_fdf *data)
{
	t_bbox	bbox;

	calculate_bounding_box(data, &bbox);
	data->shift_x = (WIN_WIDTH - (bbox.max_x - bbox.min_x)) / 2 - bbox.min_x;
	data->shift_y = (WIN_HEIGHT - (bbox.max_y - bbox.min_y)) / 2 - bbox.min_y;
}
