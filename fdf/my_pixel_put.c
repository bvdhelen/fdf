/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:05:10 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/04/23 20:20:50 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*offset;

	offset = (img->img_pixels_ptr) + ((img->line_len * y) + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)offset = color;
}
/*
int	f(int keysym, t_fdf *data)
{
	if (keysym == XK_r)
		color_screen(data, 0xff0000); //color:
	else if (keysym == XK_g)
		color_screen(data, 0x00ff00); //color:
	else if (keysym == XK_b)
		color_screen(data, 0x0000ff); //color:
	else if (keysym == XK_Escape)
		exit(1); //status:
	mlx_put_image_to_window(data->mlx_ptr, //mlx_ptr:
							data->win_ptr, //win_ptr:
							data->img.img_ptr, //img_ptr:
							0, 0); //x: y:
	return (0);
}

int	main(void)
{
	t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, //mlx_ptr:
							1000, //size_x:
							1000, //size_y:
							"My window"); //tittle:
	vars.img.img_ptr = mlx_new_image(vars.mlx, //mlx_ptr:
									1000, //width:
									1000); //height:
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr, //img_ptr:
												&vars.img.bits_per_pixel, //bits_per pixel:
												&vars.img.line_len, //size_line:
												&vars.img.endian); //endian:
	printf("Line_len %d <-> SIDE_LEN %d\n" //format:
			"bpp %d\n"
			"endian %d\n", vars.img.line_len, 1000, vars.img.bits_per_pixel, vars.img.endian);
	mlx_key_hook(vars.win, //win_ptr:
				f, //funct_ptr:
				&vars); //param:
	mlx_loop(vars.mlx); //mlx_ptr:
}
*/