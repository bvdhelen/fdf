/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 20:48:29 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/04/29 21:42:37 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	calculate_z_range(t_fdf *data, int *range_min, int *range_max)
{
	int	x;
	int	y;

	*range_min = data->z_matrix[0][0];
	*range_max = data->z_matrix[0][0];
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			if (data->z_matrix[y][x] < *range_min)
				*range_min = data->z_matrix[y][x];
			if (data->z_matrix[y][x] > *range_max)
				*range_max = data->z_matrix[y][x];
			x++;
		}
		y++;
	}
}

void	set_color(int z, t_fdf *data)
{
	int	gradient_range;
	int	color_value;

	gradient_range = data->z_max - data->z_min;
	if (gradient_range == 0)
		gradient_range = 1;
	color_value = (z - data->z_min) * 255 / gradient_range;
	if (color_value < 0)
		color_value = 0;
	if (color_value > 255)
		color_value = 255;
	data->color = (color_value << 16) | (color_value << 8) | color_value;
}

int	get_color(int z, int range_min, int range_max)
{
	float	percentage;
	int		start_color;
	int		end_color;
	int		red;
	int		green;
	int		blue;

	start_color = 0x0000FF;
	end_color = 0xFFFFFF;
	if (range_max == range_min)
		return (start_color);
	percentage = (float)(z - range_min) / (range_max - range_min);
	red = (int)((1 - percentage) * ((start_color >> 16) & 0xFF) + percentage * ((end_color >> 16) & 0xFF));
	green = (int)((1 - percentage) * ((start_color >> 8) & 0xFF) + percentage * ((end_color >> 8) & 0xFF));
	blue = (int)((1 - percentage) * (start_color & 0xFF) + percentage * (end_color & 0xFF));
	return ((red << 16 | green << 8 | blue));
}

int	set_and_get_color(int z, t_fdf *data)
{
	set_color(z, data);
	return (get_color(z, data->z_min, data->z_max));
}


//CHATTY
void calculate_and_set_color(t_fdf *data, int z)
{
    // Asegurarse de que los valores de rango estén calculados antes
    int range_min = data->z_min;
    int range_max = data->z_max;

    // Calcular el color usando los valores z, z_min y z_max
    float percentage = (float)(z - range_min) / (range_max - range_min);
    
    int start_color = 0x0000FF;  // Azul
    int end_color = 0xFFFFFF;    // Blanco

    // Calcular los componentes del color
    int red = (int)((1 - percentage) * ((start_color >> 16) & 0xFF) + percentage * ((end_color >> 16) & 0xFF));
    int green = (int)((1 - percentage) * ((start_color >> 8) & 0xFF) + percentage * ((end_color >> 8) & 0xFF));
    int blue = (int)((1 - percentage) * (start_color & 0xFF) + percentage * (end_color & 0xFF));

    // Guardar el color en data->color
    data->color = (red << 16) | (green << 8) | blue;
}
void bresenham(t_fdf *data, float x, float y, float x1, float y1)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;

    // Obtener los valores Z
    get_point_data(data, &x, &y, &z);
    get_point_data(data, &x1, &y1, &z1);
    
    // Convertir a isométrico
    isometric(&x, &y, z);
    isometric(&x1, &y1, z1);

    // Ajustar por desplazamientos
    x += data->shift_x;
    y += data->shift_y;
    x1 += data->shift_x;
    y1 += data->shift_y;

    // Calcular y asignar color para cada punto
    calculate_and_set_color(data, z);
    int color_z = data->color;  // Este es el color que puedes usar para z
    calculate_and_set_color(data, z1);
    int color_z1 = data->color; // Este es el color que puedes usar para z1

    // Ahora puedes usar los colores calculados para dibujar
    x_step = x1 - x;
    y_step = y1 - y;
    max = ft_max(ft_abs(x_step), ft_abs(y_step));
    x_step = x_step / max;
    y_step = y_step / max;

    // Dibuja los píxeles
    while ((int)(x - x1) || (int)(y - y1))
    {
        if (x >= 0 && y >= 0 && x < WIN_WIDTH && y < WIN_HEIGHT)
            my_pixel_put(&data->img, x, y, data->color);  // Usa el color de data->color
        x += x_step;
        y += y_step;
    }
}
//chatty
