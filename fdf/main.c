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
	set_default_values(data);
	init_image(data, WIN_WIDTH, WIN_HEIGHT);
	calculate_z_range(data, &data->z_min, &data->z_max);
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
