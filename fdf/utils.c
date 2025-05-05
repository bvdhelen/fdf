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

//falta usarla
void	ft_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	render(t_fdf *data)
{
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
}
