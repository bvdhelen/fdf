/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:33:19 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/05/07 21:03:33 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default_values(t_fdf *data)
{
	data->zoom = 20;
}

int	init_data(t_fdf **data, char *file_name)
{
	*data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!*data)
	{
		ft_printf("Error al reservar memoria para t_fdf.\n");
		return (0);
	}
	read_file(file_name, *data);
	if (!(*data)->z_matrix)
	{
		ft_printf("Error al leer el archivo.\n");
		free(*data);
		return (0);
	}
	return (1);
}

int	init_window(t_fdf *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "FDF");
	if (!data->win_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		return (0);
	}
	return (1);
}

void	init_image(t_fdf *data, int width, int height)
{
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	data->img.img_ptr = mlx_new_image(data->mlx_ptr, width, height);
	if (!data->img.img_ptr)
	{
		ft_printf("Error al crear la imagen.\n");
		free_all(data);
		exit(1);
	}
	data->img.img_pixels_ptr = mlx_get_data_addr(data->img.img_ptr,
			&data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
	if (!data->img.img_pixels_ptr)
	{
		ft_printf("Error al obtener dirección de píxeles de la imagen.\n");
		free_all(data);
		exit(1);
	}
}
