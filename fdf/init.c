/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:33:19 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/04/23 19:38:02 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    init_image(t_fdf *data, int width, int height)
{
    data->img.img_ptr = mlx_new_image(data->mlx_ptr, width, height);
    if (!data->img.img_ptr)
    {
        ft_printf("Error al crear la imagen.\n");
        free_all(data);
        exit(1);
    }
    data->img.img_pixels_ptr = mlx_get_data_addr(data->img.img_ptr, &data->img.bits_per_pixel, &data->img.line_len, &data->img.endian);
    if (!data->img.img_pixels_ptr)
    {
        ft_printf("Error al obtener dirección de píxeles de la imagen.\n");
        free_all(data);
        exit(1);
    }
}
