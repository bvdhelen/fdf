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

int	get_height(char *file_name)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	height = 0;
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

//la he cogido del split, a ver como le hago para no ponerla doble
static int	count_words(char const *str, char limit)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 && str[i] != limit)
			|| (str[i] != limit && str[i - 1] == limit))
			count++;
		i++;
	}
	return (count);
}

int	get_width(char *file_name)
{
	char	*line;
	int		fd;
	int		width;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	if (!line)
	{
		close(fd);
		return (-1);
	}
	width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	fill_matrix(int *z_line, char *line, int width)
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
		free(nums[i++]);
	free(nums);
}

void	read_file(char *file_name, t_fdf *data)
{
	int		i;
	int		fd;
	char	*line;

	data->height = get_height(file_name);
	data->width = get_width(file_name);
	if (data->height <= 0 || data->width <= 0)
		return ;
	data->z_matrix = (int **)malloc(sizeof(int *) * data->height);
	if (!data->z_matrix)
		return ;
	i = 0;
	while (i < data->height)
	{
		data->z_matrix[i] = (int *)malloc(sizeof(int) * data->width);
		if (!data->z_matrix[i])
			return ;
		i++;
	}
	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return ;
	i = 0;
	line = get_next_line(fd);
	while (line && i < data->height)
	{
		fill_matrix(data->z_matrix[i], line, data->width);
		free(line);
		i++;
		line = get_next_line(fd);
	}
	close(fd);
}
