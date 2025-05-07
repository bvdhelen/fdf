/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:48:29 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/05/07 21:05:04 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_color(int z, int range_min, int range_max)
{
	float	percentage;
	int		start_color;
	int		end_color;
	int		red;
	int		green;
	int		blue;

	start_color = 0x0000FF;
	end_color = 0xFFFFFF;
	if (range_max == range_min)
		return (start_color);
	percentage = (float)(z - range_min) / (range_max - range_min);
	red = (int)((1 - percentage) * ((start_color >> 16) & 0xFF)
			+ percentage * ((end_color >> 16) & 0xFF));
	green = (int)((1 - percentage) * ((start_color >> 8) & 0xFF)
			+ percentage * ((end_color >> 8) & 0xFF));
	blue = (int)((1 - percentage) * (start_color & 0xFF)
			+ percentage * (end_color & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}

int	interpolate_red(int start_color, int end_color, float percentage)
{
	int	start_r;
	int	end_r;

	start_r = (start_color >> 16) & 0xFF;
	end_r = (end_color >> 16) & 0xFF;
	return ((int)(start_r + (end_r - start_r) * percentage));
}

int	interpolate_green(int start_color, int end_color, float percentage)
{
	int	start_g;
	int	end_g;

	start_g = (start_color >> 8) & 0xFF;
	end_g = (end_color >> 8) & 0xFF;
	return ((int)(start_g + (end_g - start_g) * percentage));
}

int	interpolate_blue(int start_color, int end_color, float percentage)
{
	int	start_b;
	int	end_b;

	start_b = start_color & 0xFF;
	end_b = end_color & 0xFF;
	return ((int)(start_b + (end_b - start_b) * percentage));
}

int	get_gradient_color(int start, int end, int step_count, int steps)
{
	float	percentage;
	int		r;
	int		g;
	int		b;

	if (steps == 0)
		percentage = 0.0f;
	else
		percentage = (float)step_count / (float)steps;
	if (percentage < 0)
		percentage = 0;
	if (percentage > 1)
		percentage = 1;
	r = interpolate_red(start, end, percentage);
	g = interpolate_green(start, end, percentage);
	b = interpolate_blue(start, end, percentage);
	return ((r << 16) | (g << 8) | b);
}
