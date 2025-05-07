/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 20:10:32 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/05/07 21:06:04 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	display_instructions(t_fdf *data)
{
	int	y;

	y = 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0x0000FF, "Instrutions:");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xFFFFFF, "Translate: aswd / ASWD");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 22, y,
		0xFFFFFF, "Rotation: arrows");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xFFFFFF, "Zoom: -/+ or mouse scroll");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xFFFFFF, "Projection: ");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xFFFFFF, "Center map: c / C");
	y += 40;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xFFFFFF, "ESC: Exit");
}
