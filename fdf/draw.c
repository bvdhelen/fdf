/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:43:15 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/08/06 10:48:15 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Función que traza las líneas desde cada punto de una fila
hacia la derecha y hacia abajo*/
static void	draw_points_in_row(t_fdf *data, int y)
{
	int		x;
	t_point	p0;
	t_point	p1;

	x = 0;
	while (x < data->width)
	{
		p0.x = x;
		p0.y = y;
		if (x < data->width - 1)
		{
			p1.x = x + 1;
			p1.y = y;
			bresenham(data, p0, p1);
		}
		if (y < data->height - 1)
		{
			p1.x = x;
			p1.y = y + 1;
			bresenham(data, p0, p1);
		}
		x++;
	}
}

/*Función que recorre todas las filas del mapa
y dibuja la malla de puntos (wireframe) en la ventana.
Representación visual del modelo*/
void	draw(t_fdf *data)
{
	int		y;

	y = 0;
	while (y < data->height)
	{
		draw_points_in_row(data, y);
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}
