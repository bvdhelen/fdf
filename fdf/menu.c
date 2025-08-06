/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:14:07 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/08/06 11:14:09 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static char	*get_projection_name(int mode)
{
	if (mode == PROJ_ISOMETRIC)
		return ("Isometric");
	else if (mode == PROJ_PLANTA)
		return ("Parallel: Planta (XY)");
	else if (mode == PROJ_ALZADO)
		return ("Parallel: Alzado (XZ)");
	else if (mode == PROJ_PERFIL)
		return ("Parallel: Perfil (YZ)");
	return ("Unknown");
}*/

void	display_instructions(t_fdf *data)
{
	int		y;
	//char	*proj_str;
	//char	*zoom_str;
	//char	*temp;
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
		0xFFFFFF, "Zoom: -/+");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xFFFFFF, "Projection: I / P");
	y += 20;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xFFFFFF, "Center map: C");
	/*y += 20;
	proj_str = ft_strjoin("Projection mode: ",
		get_projection_name(data->projection_mode));
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xFFFF00, proj_str);
	free(proj_str);
	y += 20;
	zoom_str = ft_itoa(data->zoom);
	temp = ft_strjoin("Zoom: ", zoom_str);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xAAAAFF, temp);
	free(zoom_str);
	free(temp);*/
	y += 40;
	mlx_string_put(data->mlx_ptr, data->win_ptr, 20, y,
		0xFFFFFF, "ESC: Exit");
}
