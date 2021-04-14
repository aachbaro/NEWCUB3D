/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:30:59 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/30 13:47:42 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	texture_parcing(char *line, t_minfo *map)
{
	char	**splited;
	int		(**f)(char **, t_minfo *);
	char	**indic;
	int		ret;

	if (line[0] == 0)
		return (1);
	ret = 1;
	splited = ft_split(line, ' ');
	get_parcer_tab(&f);
	if (!f)
		return (error_spec(4));
	indic = get_indic_tab();
	if (!indic)
		return (error_spec(4));
	if (get_pos_tab(splited[0], indic) != -1)
		ret = (f)[get_pos_tab(splited[0], indic)](splited, map);
	else
		ret = error_spec(0);
	free(indic);
	del_strtab(splited);
	free(f);
	return (ret);
}

int	get_res(char **line, t_minfo *info)
{
	if (check_res(line) == -1)
		return (-1);
	if (info->res_x == -1 || info->res_y == -1)
	{
		info->res_x = ft_ultratoi(line[1]);
		info->res_y = ft_ultratoi(line[2]);
	}
	else
		return (error_spec(1));
	return (1);
}

int	get_north(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->tex_n)
		info->tex_n = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}

int	get_south(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->tex_s)
		info->tex_s = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}

int	get_west(char **line, t_minfo *info)
{
	int	i;

	i = 0;
	if (tab_len(line) != 2)
		return (error_spec(0));
	if (!info->tex_w)
		info->tex_w = ft_strdup(line[1]);
	else
		return (error_spec(1));
	return (1);
}
