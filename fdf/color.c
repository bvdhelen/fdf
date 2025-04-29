/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:48:29 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/04/29 20:58:53 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_color(int z, t_fdf *data)
{
	int	range_min;
	int	range_max;
	int	gradient_range;
	int	color_value;

	range_min = -10;
	range_max = 10;
	gradient_range = range_max - range_min;
	color_value = (z - range_min) * 255 / gradient_range;
	if (color_value < 0)
		color_value = 0;
	if (color_value > 255)
		color_value = 255;
	data->color = (color_value << 16) | (color_value << 8) | color_value;
}
