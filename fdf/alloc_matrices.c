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
