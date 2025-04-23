/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 19:05:10 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/04/24 00:27:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*offset;

	offset = (img->img_pixels_ptr) + ((img->line_len * y) + (x * (img->bits_per_pixel / 8)));
	*(unsigned int *)offset = color;
}
