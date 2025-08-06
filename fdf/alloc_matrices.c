/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_matrices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 10:12:22 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/08/06 10:12:22 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*Función para reservar memoria para las alturas (z)*/
int	alloc_z_matrix(t_fdf *data)
{
	int	i;

	data->z_matrix = (int **)malloc(sizeof(int *) * data->height);
	if (!data->z_matrix)
		return (0);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		if (!data->z_matrix[i])
		{
			ft_printf("Error al reservar memoria.\n");
			free_z_matrix(data);
			return (0);
		}
		i++;
	}
	return (1);
}

/*Función para reservar memoria para los colores en hexadecimal (0xFFFFFF)*/
int	alloc_color_matrix(t_fdf *data)
{
	int	i;

	data->color_matrix = (int **)malloc(sizeof(int *) * data->height);
	if (!data->color_matrix)
		return (0);
	i = 0;
	while (i < data->height)
	{
		data->color_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		if (!data->color_matrix[i])
		{
			ft_printf("Error al reservar memoria.\n");
			free_color_matrix(data);
			return (0);
		}
		i++;
	}
	return (1);
}
