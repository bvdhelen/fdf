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

int	deal_key(int key, void *data)
{
	(void)data;
	ft_printf("%d\n", key);
	return (0);
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
