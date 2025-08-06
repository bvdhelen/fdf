/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:12:49 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/08/06 11:12:49 by eldiaz-c         ###   ########.fr       */
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
	init_image(data, WIN_WIDTH, WIN_HEIGHT);
	calculate_center(data);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	display_instructions(data);
	mlx_key_hook(data->win_ptr, handle_key, data);
	mlx_hook(data->win_ptr, 17, 0, handle_event, data);
	mlx_loop(data->mlx_ptr);
	free_all(data);
	return (0);
}
