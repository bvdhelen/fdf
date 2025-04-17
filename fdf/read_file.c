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
			return (0);
		i++;
	}
	return (1);
}

static void	fill_matrix(int *z_line, char *line, int width)
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
		free(nums[i]);
		i++;
	}
	while (nums[i])
	{
		free(nums[i]);
		i++;
	}
	free(nums);
}

static void	fill_z_matrix(int fd, t_fdf *data)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line && i < data->height)
	{
		fill_matrix(data->z_matrix[i], line, data->width);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

void	read_file(char *file_name, t_fdf *data)
{
	int		fd;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (data->height <= 0 || data->width <= 0)
		return ;
	if (!alloc_z_matrix(data))
		return ;
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return ;
	fill_z_matrix(fd, data);
	close(fd);
}
