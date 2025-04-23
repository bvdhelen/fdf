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

#define MAX(a,b) (a > b ? a : b)
#define MOD(a) ((a < 0) ? -a : a)

float	mod(float i)
{
	return (i < 0) ? -i : i;
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	bresenham(float x, float y, float x1, float y1, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;
	
	z = data->z_matrix[(int)y][(int)x];
	z1 = data->z_matrix[(int)y1][(int)x1];
	//---------zoom------------
	x *= data->zoom;
	y *= data->zoom;
	x1 *= data->zoom;
	y1 *= data->zoom;

	//---------offset------------
	x += data->offset;
	y += data->offset;
	x1 += data->offset;
	y1 += data->offset;

	//---------color------------
	data->color = (z || z1) ? 0x0000ff : 0xffffff;

	//---------3D---------------
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);

	//---------shift-------------
	x += 150;
	y += 150;
	x1 += 150;
	y1 += 150;

	x_step = x1 - x;
	y_step = y1 - y;
	max = MAX(MOD(x_step), MOD(y_step));
	x_step = (x1 - x) / max;
	y_step = (y1 - y) / max;

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
				bresenham(x, y, x + 1, y, data);
			if (y < data->height - 1)
				bresenham(x, y, x, y + 1, data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img_ptr, 0, 0);
}
