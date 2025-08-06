/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:04:24 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/08/06 11:04:24 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	movement_and_rotation_keys(int key, t_fdf *data)
{
	if (key == XK_a || key == XK_A)
		data->shift_x -= 10;
	else if (key == XK_s || key == XK_S)
		data->shift_y += 10;
	else if (key == XK_w || key == XK_W)
		data->shift_y -= 10;
	else if (key == XK_d || key == XK_D)
		data->shift_x += 10;
	else if (key == 65363)
		data->theta -= (PI / 32);
	else if (key == 65361)
		data->theta += (PI / 32);
	else if (key == 65362)
		data->phi += (PI / 32);
	else if (key == 65364)
		data->phi -= (PI / 32);
}

static void	zoom_and_flatten_keys(int key, t_fdf *data)
{
	if (key == XK_plus)
		data->zoom += 1;
	else if (key == XK_minus && data->zoom > 1)
		data->zoom -= 1;
	else if ((key == XK_l || key == XK_L))
		data->z_factor -= 0.1;
	else if (key == XK_h || key == XK_H)
		data->z_factor += 0.1;
}

static void	projection_and_center_keys(int key, t_fdf *data)
{
	if (key == XK_i || key == XK_I)
		data->projection_mode = PROJ_ISOMETRIC;
	else if (key == XK_p || key == XK_P)
	{
		if (data->projection_mode < PROJ_PLANTA
			|| data->projection_mode > PROJ_PERFIL)
			data->projection_mode = PROJ_PLANTA;
		else
			data->projection_mode = PROJ_PLANTA
				+ ((data->projection_mode - PROJ_PLANTA + 1) % 3);
	}
	else if (key == XK_c || key == XK_C)
		calculate_center(data);
}

int	handle_key(int key, t_fdf *data)
{
	if (key == XK_Escape)
	{
		ft_printf("Program closed using the 'ESC' key\n");
		free_all(data);
		exit(0);
	}
	movement_and_rotation_keys(key, data);
	zoom_and_flatten_keys(key, data);
	projection_and_center_keys(key, data);
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
	ft_printf("Program closed using the 'x' button\n");
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