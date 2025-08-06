/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:48:38 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/08/06 10:48:38 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Función que libera la memoria de la matriz de alturas (z_matrix)*/
void	free_z_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	if (!data || !data->z_matrix)
		return ;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
}

/*Función que libera la memoria de la matriz de colores (color_matrix)*/
void	free_color_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	if (!data->color_matrix)
		return ;
	while (i < data->height)
	{
		free(data->color_matrix[i]);
		i++;
	}
	free(data->color_matrix);
}

/*Función que libera toda la memoria y recursos gráficos asociados a data
Limpia la estructura t_fdf y los elementos asignados dinámicamente*/
void	free_all(t_fdf *data)
{
	if (!data)
		return ;
	if (data->z_matrix)
		free_z_matrix(data);
	if (data->color_matrix)
		free_color_matrix(data);
	if (data->img.img_ptr)
		mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free(data);
}
