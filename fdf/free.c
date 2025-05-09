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

//color_matrix
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

//z_matrix
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
