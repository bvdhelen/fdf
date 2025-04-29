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

void	calculate_center(t_fdf *data)
{
	int		x;
	int		y;
	float	proj_x;
	float	proj_y;
	float	min_x;
	float	max_x;
	float	min_y;
	float	max_y;

	min_x = FLOAT_MAX;
	max_x = FLOAT_MIN;
	min_y = FLOAT_MAX;
	max_y = FLOAT_MIN;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			proj_x = x * data->zoom + data->offset;
			proj_y = y * data->zoom + data->offset;
			isometric(&proj_x, &proj_y, data->z_matrix[y][x]);
			if (proj_x < min_x)
				min_x = proj_x;
			if (proj_x > max_x)
				max_x = proj_x;
			if (proj_y < min_y)
				min_y = proj_y;
			if (proj_y > max_y)
				max_y = proj_y;
			x++;
		}
		y++;
	}
	data->shift_x = (WIN_WIDTH - (max_x - min_x)) / 2 - min_x;
	data->shift_y = (WIN_HEIGHT - (max_y - min_y)) / 2 - min_y;
}

static int	validate_args(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Uso correcto del programa: %s <map_file>\n", argv[0]);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (!validate_args(argc, argv)
		|| !init_data(&data, argv[1])
		|| !init_window(data))
		return (1);
	data->zoom = 20;
	data->offset = 200;
	init_image(data, WIN_WIDTH, WIN_HEIGHT);
	calculate_center(data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	mlx_key_hook(data->win_ptr, handle_key, data);
	mlx_hook(data->win_ptr, 17, 0, handle_event, data);
	mlx_loop(data->mlx_ptr);
	free_all(data);
	return (0);
}
