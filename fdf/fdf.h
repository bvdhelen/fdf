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
# include <math.h> 

# define FLOAT_MAX 3.402823466e+38F
# define FLOAT_MIN -3.402823466e+38F
# define WIN_WIDTH 1000
# define WIN_HEIGHT 1000
# define PI 3.14159265358979

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
	//int		offset;
	int		color;
	int		shift_x;
	int		shift_y;
	int		z_min;
	int		z_max;
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

void	isometric(float *x, float *y, int z);
void	get_point_data(t_fdf *data, float *x, float *y, int *z);
void	bresenham(t_fdf *data, float x, float y, float x1, float y1);
void	draw(t_fdf *data);

void	my_pixel_put(t_img *img, int x, int y, int color);

int		init_data(t_fdf **data, char *file_name);
int		init_window(t_fdf *data);
void	init_image(t_fdf *data, int width, int height);

int		handle_event(t_fdf *data);
int		handle_key(int key, t_fdf *data);

float	ft_abs(float num);
float	ft_max(float a, float b);

void	calculate_z_range(t_fdf *data, int *range_min, int *range_max);
int		get_color(int z, int range_min, int range_max);

int		get_gradient_color(int color_start, int color_end, int step_count, int steps);
int		interpolate_blue(int start_color, int end_color, float percentage);
int		interpolate_green(int start_color, int end_color, float percentage);
int		interpolate_red(int start_color, int end_color, float percentage);

void	render(t_fdf *data);
void	ft_error(char *msg);
void	set_default_values(t_fdf *data);
void	calculate_center(t_fdf *data);

#endif
