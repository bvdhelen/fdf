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

static void	free_matrix(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
}

static void	print_matrix(t_fdf *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			ft_printf("%d", data->z_matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2)
	{
		ft_printf("Uso correcto del programa: %s <map_file>\n", argv[0]);
		return (1);
	}
	data = (t_fdf *)malloc(sizeof(t_fdf));
	if (!data)
	{
		ft_printf("Error al reservar memoria para t_fdf.\n");
		return (1);
	}
	read_file(argv[1], data);
	if (!data->z_matrix)
	{
		ft_printf("Error al leer el archivo.\n");
		free(data);
		return (1);
	}
	print_matrix(data);
	free_matrix(data);
	free(data);
	return (0);
}
