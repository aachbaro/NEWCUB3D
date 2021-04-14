/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:27:43 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/30 13:30:53 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		get_info(int *fd, t_minfo *map, char *file)
{
	int		ret;
	int		error;
	char	*line;

	ret = 1;
	while (get_next_line(*fd, &line) && !is_map_line(line))
	{
		error = texture_parcing(line, map);
		free(line);
		if (error == -1)
			return (-1);
	}
	if (is_map_line(line))
	{
		map->map_x = ft_strlen(line);
		map->map_y++;
		free(line);
	}
	error = get_map(fd, &line, map, file);
	if (check_maptab(map) == -1 || error == -1 || check_mapinfo(*map) == -1)
		return (-1);
	return (0);
}
