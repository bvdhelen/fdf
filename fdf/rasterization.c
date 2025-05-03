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

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*offset;

	offset = (img->img_pixels_ptr)
		+ ((img->line_len * y) + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)offset = color;
}

void	isometric(float *x, float *y, int z)
{
	float	rot_display_x;
	float	rot_display_y;
	float	rot_x;
	float	rot_y;
	float	angle;

	(void)z;
	angle = PI/4;
	rot_display_x = *x;
	rot_display_y = *y;
	*x = (rot_display_x) * cos(angle) - (rot_display_y) * sin(angle);
	*y = (rot_display_x) * sin(angle) + (rot_display_y) * cos(angle);
	rot_x = *x;
	rot_y = *y;
	*x = (rot_x);
	*y = (rot_y) * cos(angle) - z;
}

void	get_point_data(t_fdf *data, float *x, float *y, int *z)
{
	int	xi;
	int	yi;

	xi = (int)*x;
	yi = (int)*y;
	*z = data->z_matrix[yi][xi];
	*x = *x * data->zoom;
	*y = *y * data->zoom;
}

void	bresenham(t_fdf *data, float x, float y, float x1, float y1)
{
	float	x_step;
	float	y_step;
	int		max;
	int		z;
	int		z1;
	int		color_start;
	int		color_end;
	int		step_count;
	int		steps;

	get_point_data(data, &x, &y, &z);
	get_point_data(data, &x1, &y1, &z1);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	x += data->shift_x;
	y += data->shift_y;
	x1 += data->shift_x;
	y1 += data->shift_y;
	color_start = get_color(z, data->z_min, data->z_max);
	color_end = get_color(z1, data->z_min, data->z_max);
	x_step = x1 - x;
	y_step = y1 - y;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	if (max == 0)
		return ;
	x_step = x_step / max;
	y_step = y_step / max;
	step_count = 0;
	steps = max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
			my_pixel_put(&data->img, x, y,
				get_current_color(color_start, color_end, step_count, steps));
		x += x_step;
		y += y_step;
		step_count++;
	}
}
