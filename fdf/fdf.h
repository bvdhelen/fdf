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

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <stdio.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "get_next_line/get_next_line.h"
# include "../mlx_linux/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}	t_img;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**z_matrix;
	int		zoom;
	int		offset;
	int		color;
	t_img	img;

	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;


int		get_height(char *file_name);
int		get_width(char *file_name);
void	read_file(char *file_name, t_fdf *data);

int		handle_key(int key, t_fdf *data);

void	free_matrix(t_fdf *data);
void	free_all(t_fdf *data);

void	bresenham(float x, float y, float x1, float y1, t_fdf *data);
void	draw(t_fdf *data);

void	my_pixel_put(t_img *img, int x, int y, int color);

void    init_image(t_fdf *data, int width, int height);

#endif
