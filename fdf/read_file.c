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

static int	alloc_color_matrix(t_fdf *data)
{
	int	i;

	data->color_matrix = (int **)malloc(sizeof(int *) * data->height);
	if (!data->color_matrix)
		return (0);
	i = 0;
	while (i < data->height)
	{
		data->color_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		if (!data->color_matrix[i])
		{
			ft_printf("Error al reservar memoria.\n");
			free_color_matrix(data);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	alloc_z_matrix(t_fdf *data)
{
	int	i;

	data->z_matrix = (int **)malloc(sizeof(int *) * data->height);
	if (!data->z_matrix)
		return (0);
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		if (!data->z_matrix[i])
		{
			ft_printf("Error al reservar memoria.\n");
			free_z_matrix(data);
			return (0);
		}
		i++;
	}
	return (1);
}

void	parse_nums_and_color(const char *str, int *z, int *color)
{
	char	*comma;
	char	*num;

	comma = ft_strchr(str, ',');
	if (comma)
	{
		num = ft_substr(str, 0, comma - str);
		if (!num)
			return ;
		*z = ft_atoi(num);
		*color = ft_hex_to_int(comma + 1);
		free(num);
	}
	else
	{
		*z = ft_atoi(str);
		*color = 0xFFFFFF;
	}
}

static void	fill_matrix_with_colors(int *z_line, int *color_line, char *line, int width)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
		return ;
	i = 0;
	while (nums[i] && i < width)
	{
		parse_nums_and_color(nums[i], &z_line[i], &color_line[i]);
		i++;
	}
	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

//esta no se va a llamar
/*static void	fill_matrix(int *z_line, char *line, int width)
{
	char	**nums;
	int		i;

	nums = ft_split(line, ' ');
	if (!nums)
		return ;
	i = 0;
	while (nums[i] && i < width)
	{
		z_line[i] = ft_atoi(nums[i]);
		i++;
	}
	i = 0;
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}*/

//fill_z_matrix antes
static void	fill_matrices(int fd, t_fdf *data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line && i < data->height)
	{
		fill_matrix_with_colors(data->z_matrix[i], data->color_matrix[i], line, data->width);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	free(line);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (data->height <= 0 || data->width <= 0)
		return ;
	if (!alloc_z_matrix(data) || !alloc_color_matrix(data))
		return ;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return ;
	fill_matrices(fd, data);
	close(fd);
}
