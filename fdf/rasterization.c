/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:37:32 by eldiaz-c          #+#    #+#             */
/*   Updated: 2024/10/27 04:04:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	isometric(float *x, float *y, int z)
{
	float	temp_x;
	float	temp_y;

	temp_x = *x;
	temp_y = *y;
	*x = (temp_x - temp_y) * cos(0.8);
	*y = (temp_x + temp_y) * sin(0.8) - z;
}
/*
void	set_pixel_data(t_fdf *data, float *x, float *y, int *z, int *z1)
{
	
	*z1 = data->z_matrix[yi][xi];
	if (yi + 1 < data->height && xi + 1 < data->width)
		*z1 = data->z_matrix[yi + 1][xi + 1];
	
	*x += data->offset;
	*x += 150;
	*y *= data->zoom;
	*y += data->offset;
}*/

void	get_point_data(t_fdf *data, float *x, float *y, int *z)
{
	int	xi;
	int	yi;

	xi = (int)*x;
	yi = (int)*y;
	*z = data->z_matrix[yi][xi];
	*x = *x * data->zoom + data->offset;
	*y = *y * data->zoom + data->offset;
}

void	bresenham(t_fdf *data, float x, float y, float x1, float y1)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;

	get_point_data(data, &x, &y, &z);
	get_point_data(data, &x1, &y1, &z1);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;
	if (z || z1)
		data->color = 0x0000ff;
	else
		data->color = 0xffffff;
	x_step = x1 - x;
	y_step = y1 - y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step = x_step / max;
	y_step = y_step / max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (x >= 0 && y >= 0 && x < 1000 && y < 1000)
			my_pixel_put(&data->img, x, y, data->color);
		x += x_step;
		y += y_step;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (x < data->width - 1)
				bresenham(data, x, y, x + 1, y);
			if (y < data->height - 1)
				bresenham(data, x, y, x, y + 1);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}
