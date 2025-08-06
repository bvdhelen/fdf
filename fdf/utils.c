/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eldiaz-c <eldiaz-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/06 11:15:29 by eldiaz-c          #+#    #+#             */
/*   Updated: 2025/08/06 11:15:29 by eldiaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	ft_abs(float num)
{
	if (num < 0)
		return (-num);
	return (num);
}

float	ft_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_hex_to_int(const char *hex)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	if (hex[0] == '0' && (hex[1] == 'x' || hex[1] == 'X'))
		i = 2;
	while (hex[i])
	{
		result *= 16;
		if (hex[i] >= '0' && hex[i] <= '9')
			result += hex[i] - '0';
		else if (hex[i] >= 'A' && hex[i] <= 'F')
			result += hex[i] - 'A' + 10;
		else if (hex[i] >= 'a' && hex[i] <= 'f')
			result += hex[i] - 'a' + 10;
		else
			break ;
		i++;
	}
	return (result);
}
