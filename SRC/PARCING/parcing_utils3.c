/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:12:28 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/30 14:45:29 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_mapinfo(t_minfo info)
{
	if (info.res_x == -1 || info.res_y == -1)
		return (error_spec(8));
	if (info.floor_color == -1 || info.ceil_color == -1)
		return (error_spec(8));
	if (!info.tex_n || !info.tex_s || !info.tex_w || !info.tex_e)
		return (error_spec(8));
	if (!info.sprite)
		return (error_spec(8));
	if (!info.pos.dir)
		return (error_spec(8));
	return (1);
}

int	check_comma(char *str)
{
	size_t	i;
	int		comma;

	i = 0;
	comma = 0;
	while (i <= ft_strlen(str))
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		while (ft_isdigit(str[i]))
			i++;
		if (str[i] == ',')
			comma++;
		i++;
	}
	if (comma != 2)
		return (-1);
	return (1);
}
