/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:26:20 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/30 14:09:12 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int			check_rgb(char **rgb)
{
	int	i;
	int	j;

	j = 0;
	while (rgb[j])
	{
		i = 0;
		while (rgb[j][i])
		{
			if (ft_isdigit(rgb[j][i]) == 0)
				return (-1);
			i++;
		}
		if (ft_atoi(rgb[j]) < 0 || ft_atoi(rgb[j]) > 255)
			return (-1);
		j++;
	}
	if (j != 3)
		return (-1);
	return (1);
}

int			rgb_trad(int r, int g, int b)
{
	return (r * 65536 + g * 256 + b);
}

long long	ft_ultratoi(const char *str)
{
	int			i;
	long long	nbr;

	i = 0;
	nbr = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\n' || str[i] == '\f')
		i++;
	while (str[i] <= '9' && str[i] >= '0')
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr);
}

int			check_res(char **line)
{
	int	i;

	i = 0;
	while (line[1][i])
	{
		if (!ft_isdigit(line[1][i]))
			return (error_spec(0));
		i++;
	}
	while (line[2][i])
	{
		if (!ft_isdigit(line[2][i]))
			return (error_spec(0));
		i++;
	}
	return (0);
}

int		is_map_line(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (0);
	while (line[i])
	{
		if (get_pos(" 012NSEW", line[i]) == -1)
			return (0);
		i++;
	}
	if (ft_strlen(line) == 0)
		return (0);
	return (1);
}
