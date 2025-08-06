/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 14:03:09 by marvin            #+#    #+#             */
/*   Updated: 2025/05/06 14:03:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*offset;

	offset = (img->img_pixels_ptr)
		+ ((img->line_len * y) + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)offset = color;
}

//Planta: Proyección paralela sobre XY (vista desde arriba)
void	proj_planta(float *x, float *y, int z, t_fdf *data)
{
	(void)data;
	(void)x;
	*y = *y - z;
}

//Alzado: Proyección paralela sobre XZ (vista frontal)
void	proj_alzado(float *x, float *y, int z, t_fdf *data)
{
	(void)data;
	(void)x;
	*y = -z;
}

//Perfil: Proyección paralela sobre YZ (vista lateral)
void	proj_perfil(float *x, float *y, int z, t_fdf *data)
{
	(void)data;
	*x = *y;
	*y = -z;
}

//Proyección isométrica
void	isometric(float *x, float *y, int z, t_fdf *data)
{
	float	rot_disp_x;
	float	rot_disp_y;
	float	rot_x;
	float	rot_y;

	(void)z;
	rot_disp_x = *x;
	rot_disp_y = *y;
	*x = (rot_disp_x) * cos(data->theta) - (rot_disp_y) * sin(data->theta);
	*y = (rot_disp_x) * sin(data->theta) + (rot_disp_y) * cos(data->theta);
	rot_x = *x;
	rot_y = *y;
	*x = (rot_x);
	*y = (rot_y) * cos(data->phi) - z;
}
