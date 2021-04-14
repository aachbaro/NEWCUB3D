/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 13:26:20 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/12 16:26:07 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		print_square(t_img *img, int squa_size, t_inipos coord, int color)
{
	int	i;
	int	j;

	j = 0;
	coord.pos_x = coord.pos_x * squa_size + 10;
	coord.pos_y = coord.pos_y * squa_size + 10;
	while (j < squa_size)
	{
		i = 0;
		coord.pos_x -= squa_size;
		while (i < squa_size)
		{
			img_pix_put(img, coord.pos_x + 10, coord.pos_y, color);
			coord.pos_x++;
			i++;
		}
		j++;
		coord.pos_y++;
	}
	return (squa_size);
}

int		color_set(char c)
{
	if (c == '1')
		return (rgb_trad(50, 100, 255));
	else if (c == '0')
		return (rgb_trad(255, 255, 255));
	else if (c == '2')
		return (rgb_trad(255, 255, 100));
	else
		return (rgb_trad(0, 0, 0));
}

void	render_minimap(t_mlxdt *data)
{
	t_inipos	coord;
	t_inipos	player;
	int			squa_size;
	int			color;

	squa_size = 10;
	player.pos_x = (int)data->ray.pos_x;
	player.pos_y = (int)data->ray.pos_y;
	coord.pos_y = 0;
	while (data->info->map[coord.pos_y])
	{
		coord.pos_x = 0;
		while (data->info->map[coord.pos_y][coord.pos_x])
		{
			color = color_set(data->info->map[coord.pos_y][coord.pos_x]);
			print_square(&data->img, squa_size, coord, color);
			print_square(&data->img, squa_size, player, rgb_trad(1, 0, 0));
			coord.pos_x++;
		}
		coord.pos_y++;
	}
}
