/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:43:33 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/05 15:09:13 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		get_map_size(int *fd, char *line, t_minfo *info)
{
	while (get_next_line(*fd, &line) && is_map_line(line))
	{
		if (ft_strlen(line) > info->map_x)
			info->map_x = ft_strlen(line);
		info->map_y++;
		free(line);
	}
	if (!is_map_line(line))
	{
		free(line);
		while (get_next_line(*fd, &line))
		{
			if (line[0] != 0)
			{
				free(line);
				return (error_spec(3));
			}
			free(line);
		}
	}
	free(line);
	info->map = malloc(sizeof(char *) * info->map_y + 1);
	if (!info->map)
		return (error_spec(4));
	return (0);
}

int		fill_mapline(char *line, t_minfo *info, int y)
{
	unsigned int	i;

	i = 0;
	info->map[y] = malloc(sizeof(char) * info->map_x + 1);
	if (!info->map[y])
		return (error_spec(4));
	while (line[i])
	{
		info->map[y][i] = line[i];
		i++;
	}
	while (i < info->map_x)
	{
		info->map[y][i] = ' ';
		i++;
	}
	info->map[y][i] = 0;
	return (1);
}

int		check_maptab(t_minfo *info)
{
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (info->map[j])
	{
		i = 0;
		while (info->map[j][i])
		{
			if (check_border(info->map, i, j) == -1 || (info->map[j][i] == ' ' \
						&& check_mspaces(info->map, i, j) == -1))
				return (error_spec(5));
			if (get_pos("NESW", info->map[j][i]) != -1 && !info->pos.dir)
				set_pos(info, j, i);
			else if (get_pos("NESW", info->map[j][i]) != -1 && info->pos.dir)
				return (error_spec(6));
			i++;
		}
		j++;
	}
	return (1);
}

int		check_mspaces(char **tab, int x, int y)
{
	int	l;
	int	h;

	l = ft_strlen(tab[0]) - 1;
	h = tab_len(tab) - 1;
	if (y > 0 && x > 0 && get_pos(" 1", tab[y - 1][x - 1]) == -1)
		return (-1);
	if (y > 0 && get_pos(" 1", tab[y - 1][x]) == -1)
		return (-1);
	if (y > 0 && x < l && get_pos(" 1", tab[y - 1][x + 1]) == -1)
		return (-1);
	if (x > 0 && get_pos(" 1", tab[y][x - 1]) == -1)
		return (-1);
	if (x < l && get_pos(" 1", tab[y][x + 1]) == -1)
		return (-1);
	if (y < h && x > 0 && get_pos(" 1", tab[y + 1][x - 1]) == -1)
		return (-1);
	if (y < h && get_pos(" 1", tab[y + 1][x]) == -1)
		return (-1);
	if (y < h && x < l && get_pos(" 1", tab[y + 1][x + 1]) == -1)
		return (-1);
	return (1);
}

int		get_map(int *fd, char **line, t_minfo *info, char *file)
{
	unsigned int	y;
	int				error;

	y = 0;
	error = get_map_size(fd, *line, info);
	if (error == -1)
		return (-1);
	close(*fd);
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (error_spec(7));
	while (get_next_line(*fd, line))
	{
		if (is_map_line(*line))
		{
			error = fill_mapline(*line, info, y);
			if (error == -1)
				return (-1);
			y++;
		}
		free(*line);
	}
	info->map[y] = NULL;
	free(*line);
	return (error);
}
