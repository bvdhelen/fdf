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

void	isometric(float *x, float *y, int z)
{
	float	rot_display_x;
	float	rot_display_y;
	float	rot_x;
	float	rot_y;
	float	angle;

	(void)z;
	angle = PI / 4;
	rot_display_x = *x;
	rot_display_y = *y;
	*x = (rot_display_x) * cos(angle) - (rot_display_y) * sin(angle);
	*y = (rot_display_x) * sin(angle) + (rot_display_y) * cos(angle);
	rot_x = *x;
	rot_y = *y;
	*x = (rot_x);
	*y = (rot_y) * cos(angle) - z;
}
