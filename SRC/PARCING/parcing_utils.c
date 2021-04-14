/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:14:07 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/30 13:50:15 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		check_border(char **tab, int x, int y)
{
	int	l;
	int	h;

	l = ft_strlen(tab[0]) - 1;
	h = tab_len(tab) - 1;
	if ((x == 0 || y == 0 || x == l || y == h) \
			&& get_pos(" 1", tab[y][x]) == -1)
		return (-1);
	return (1);
}

int		set_pos(t_minfo *info, int y, int x)
{
	info->pos.pos_x = x;
	info->pos.pos_y = y;
	info->pos.dir = info->map[y][x];
	info->map[y][x] = '0';
	return (1);
}

int		error_spec(int n)
{
	ft_putstr_fd("Error\n", 1);
	if (n == 0)
		ft_putstr_fd("Invalid texture line\n", 1);
	if (n == 1)
		ft_putstr_fd("Texture found twice\n", 1);
	if (n == 2)
		ft_putstr_fd("Invalid RGB definition\n", 1);
	if (n == 3)
		ft_putstr_fd("Invalid line after map definition\n", 1);
	if (n == 4)
		ft_putstr_fd("Malloc failed\n", 1);
	if (n == 5)
		ft_putstr_fd("Map not closed\n", 1);
	if (n == 6)
		ft_putstr_fd("Initial position found twice\n", 1);
	if (n == 7)
		ft_putstr_fd("Open failed\n", 1);
	if (n == 8)
		ft_putstr_fd("Information missing", 1);
	return (-1);
}

char	**get_indic_tab(void)
{
	char	**indic;

	indic = malloc(sizeof(char *) * 9);
	if (!indic)
		return (NULL);
	indic[0] = "R";
	indic[1] = "NO";
	indic[2] = "SO";
	indic[3] = "WE";
	indic[4] = "EA";
	indic[5] = "S";
	indic[6] = "F";
	indic[7] = "C";
	indic[8] = NULL;
	return (indic);
}

int		get_parcer_tab(int (***f)(char **, t_minfo *))
{
	(*f) = malloc(sizeof(*f) * 8);
	if (!(*f))
		return (-1);
	(*f)[0] = &get_res;
	(*f)[1] = &get_north;
	(*f)[2] = &get_south;
	(*f)[3] = &get_west;
	(*f)[4] = &get_east;
	(*f)[5] = &get_sprite;
	(*f)[6] = &get_floor;
	(*f)[7] = &get_ceil;
	return (1);
}
