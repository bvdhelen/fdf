/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:05:10 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/04/29 19:53:35 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
