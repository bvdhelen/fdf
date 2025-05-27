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

//valores de pixel de *z, *x, *y que se mantienen con el zoom y 
//los de la z se multiplican por un factor de escala constante
void	get_point_data(t_fdf *data, t_point *point)
{
	int	xi;
	int	yi;

	xi = (int)(point->x);
	yi = (int)(point->y);
	point->z = (data->z_matrix[yi][xi] * data->zoom) * 0.1;
	point->color = data->color_matrix[yi][xi];
	point->x *= data->zoom;
	point->y *= data->zoom;
}

static void	init_bres(t_fdf *data, t_point *p0, t_point *p1, t_bresenham *bres)
{
	get_point_data(data, p0);
	get_point_data(data, p1);
	isometric(&p0->x, &p0->y, p0->z);
	isometric(&p1->x, &p1->y, p1->z);
	p0->x += data->shift_x;
	p0->y += data->shift_y;
	p1->x += data->shift_x;
	p1->y += data->shift_y;
	bres->x_step = p1->x - p0->x;
	bres->y_step = p1->y - p0->y;
	bres->max = ft_max(ft_abs(bres->x_step), ft_abs(bres->y_step));
	if (bres->max == 0)
		return ;
	bres->x_step /= bres->max;
	bres->y_step /= bres->max;
	bres->step_count = 0;
	bres->steps = bres->max;
}

static void	draw_bres(t_fdf *data, t_point p0, t_point p1, t_bresenham bres)
{
	while ((int)(p0.x - p1.x) || (int)(p0.y - p1.y))
	{
		if (p0.x >= 0 && p0.y >= 0 && p0.x < WIN_WIDTH && p0.y < WIN_HEIGHT)
			my_pixel_put(&data->img, p0.x, p0.y,
				get_gradient_color(p0.color, p1.color,
					bres.step_count, bres.steps));
		p0.x += bres.x_step;
		p0.y += bres.y_step;
		bres.step_count++;
	}
}

void	bresenham(t_fdf *data, t_point p0, t_point p1)
{
	t_bresenham	bres;

	init_bres(data, &p0, &p1, &bres);
	if (bres.max > 0)
		draw_bres(data, p0, p1, bres);
}
