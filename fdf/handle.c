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
	if (key == XK_a || key == XK_A)
		data->shift_x -= 10;
	if (key == XK_s || key == XK_S)
		data->shift_y += 10;
	if (key == XK_w || key == XK_W)
		data->shift_y -= 10;
	if (key == XK_d || key == XK_D)
		data->shift_x += 10;
	else if (key == XK_plus)
	{
		data->zoom += 1;
		calculate_center(data);
		render(data);
	}
	else if (key == XK_minus && data->zoom > 1)
	{
		data->zoom -= 1;
		calculate_center(data);
		render(data);
	}
	else if (key == XK_c || key == XK_C)
	{
		calculate_center(data);
		render(data);
	}
	ft_printf("The %d key has been pressed\n\n", key);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	init_image(data, WIN_WIDTH, WIN_HEIGHT);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.img_ptr, 0, 0);
	return (0);
}

int	handle_event(t_fdf *data)
{
	ft_printf("Program closed using the 'x' button\n\n");
	free_all(data);
	exit(0);
	return (0);
}

//mirala guarra
int	handle_mouse_scroll(int button, int x, int y, t_fdf *data)
{
	(void)x;
	(void)y;
	if (button == 4)
		data->zoom += 1;
	else if (button == 5 && data->zoom > 1)
		data->zoom -= 1;
	else
		return (0);
	calculate_center(data);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	init_image(data, WIN_WIDTH, WIN_HEIGHT);
	render(data);
	return (0);
}

//MODIFICA MIJA
void	display_instructions(t_fdf *data)
{
	int	y;

	y = 10;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y,
		0xFFFFFF, "Colores disponibles:");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y,
		0xFFFFFF, "1: Azul -> Blanco");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y,
		0xFFFFFF, "2: Rojo -> Amarillo");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y,
		0xFFFFFF, "3: Verde -> Blanco");
	y += 40;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 10, y,
		0xFFFFFF, "ESC: Salir");
}
