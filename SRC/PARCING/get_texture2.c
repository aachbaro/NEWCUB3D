/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:34:08 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/30 13:49:43 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	get_east(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->tex_e)
		info->tex_e = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}

int	get_sprite(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->sprite)
		info->sprite = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}

int	get_floor(char **line, t_minfo *info)
{
	char	**splited;

	if (tab_len(line) != 2 || check_comma(line[1]) == -1)
		return (error_spec(0));
	splited = ft_split(line[1], ',');
	if (check_rgb(splited) == -1)
	{
		del_strtab(splited);
		return (error_spec(2));
	}
	if (info->floor_color == -1)
	{
		info->floor_color = rgb_trad(ft_atoi(splited[0]),
				ft_atoi(splited[1]), ft_atoi(splited[2]));
		del_strtab(splited);
	}
	else
	{
		del_strtab(splited);
		return (error_spec(1));
	}
	return (1);
}

int	get_ceil(char **line, t_minfo *info)
{
	char	**splited;

	if (tab_len(line) != 2 || check_comma(line[1]) == -1)
		return (error_spec(0));
	splited = ft_split(line[1], ',');
	if (check_rgb(splited) == -1)
	{
		del_strtab(splited);
		return (error_spec(2));
	}
	if (info->ceil_color == -1)
	{
		info->ceil_color = rgb_trad(ft_atoi(splited[0]),
				ft_atoi(splited[1]), ft_atoi(splited[2]));
		del_strtab(splited);
	}
	else
	{
		del_strtab(splited);
		return (error_spec(1));
	}
	return (1);
}
