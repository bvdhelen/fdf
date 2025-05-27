/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:48:29 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/05/27 20:30:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
