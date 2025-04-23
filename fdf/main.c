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

int	handle_key(int key, t_fdf *data)
{
	if (key == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", key);
		free_all(data);
		exit(0);
	}
	ft_printf("The %d key has been pressed\n\n", key);
	return (0);
}

int	handle_event(t_fdf *data)
{
	ft_printf("Program closed using the 'x' button\n\n");
	free_all(data);
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		ft_printf("Uso correcto del programa: %s <map_file>\n", argv[0]);
		return (1);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
	{
		ft_printf("Error al reservar memoria para t_fdf.\n");
		return (1);
	}
	read_file(argv[1], data);
	if (!data->z_matrix)
	{
		ft_printf("Error al leer el archivo.\n");
		free(data);
		return (1);
	}
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (1);
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (1);
	}
	data->zoom = 20;
	data->offset = 200;
	init_image(data, 1000, 1000);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	mlx_key_hook(data->win_ptr, handle_key, data);
	mlx_hook(data->win_ptr, 17, 0, handle_event, data);
	mlx_loop(data->mlx_ptr);
	free_all(data);
	return (0);
}
