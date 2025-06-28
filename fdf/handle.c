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

void	key_imput(int key, t_fdf *data)
{
	if (key == XK_Escape)
	{
		ft_printf("The %d key (ESC) has been pressed\n\n", key);
		free_all(data);
		exit(0);
	}
	if (key == XK_a || key == XK_A)
		data->shift_x -= 10;
	if (key == XK_s || key == XK_S)
		data->shift_y += 10;
	if (key == XK_w || key == XK_W)
		data->shift_y -= 10;
	if (key == XK_d || key == XK_D)
		data->shift_x += 10;
	else if (key == XK_plus)
		data->zoom += 1;
	else if (key == XK_minus && data->zoom > 1)
		data->zoom -= 1;
	else if (key == XK_c || key == XK_C)
		calculate_center(data);
	else if ((key == XK_n || key == XK_N))
		data->z_factor -= 0.1;
	else if (key == XK_m || key == XK_M)
		data->z_factor += 0.1;
	else if (key == 65363)
		data->theta -= (PI / 16);
	else if (key == 65361)
		data->theta += (PI / 16);
	else if (key == 65362)
		data->phi += (PI / 16);
	else if (key == 65364)
		data->phi -= (PI / 16);
}

int	handle_key(int key, t_fdf *data)
{
	key_imput(key, data);
	ft_printf("The %d key has been pressed\n\n", key);
	init_image(data, WIN_WIDTH, WIN_HEIGHT);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	display_instructions(data);
	return (0);
}

int	handle_event(t_fdf *data)
{
	ft_printf("Program closed using the 'x' button\n\n");
	free_all(data);
	exit(0);
	return (0);
}
/*
int	handle_mouse(int button, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (button == 1)
		ft_printf("Left mouse button pressed at (%d, %d)!\n", x, y);
	else if (button == 3)
		ft_printf("Right mouse button pressed at (%d, %d)!\n", x, y);
	else if (button == 4)
	{
		ft_printf("Zoom in at (%d, %d)!\n", x, y);
		data->zoom += 1;
	}
	else if (button == 5 && data->zoom > 1)
	{
		ft_printf("Zoom out at (%d, %d)!\n", x, y);
		data->zoom -= 1;
	}
	else
		return (0);
	calculate_center(data);
	init_image(data, WIN_WIDTH, WIN_HEIGHT);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	display_instructions(data);
	return (0);
}
*/