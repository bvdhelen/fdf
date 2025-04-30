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

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

void	calculate_z_range(t_fdf *data, int *range_min, int *range_max)
{
	int	x;
	int	y;

	*range_min = data->z_matrix[0][0];
	*range_max = data->z_matrix[0][0];
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->z_matrix[y][x] < *range_min)
				*range_min = data->z_matrix[y][x];
			if (data->z_matrix[y][x] > *range_max)
				*range_max = data->z_matrix[y][x];
			x++;
		}
		y++;
	}
}
