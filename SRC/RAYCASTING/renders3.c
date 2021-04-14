/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renders3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 16:12:06 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/12 14:26:46 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	get_perpwalldist(t_ray *ray, int res_y)
{
	if (ray->side == 0)
		ray->perpwalldist = ((double)ray->map_x - ray->pos_x +
				(1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpwalldist = ((double)ray->map_y - ray->pos_y +
				(1 - ray->step_y) / 2) / ray->raydir_y;
	ray->lineh = (int)(res_y / ray->perpwalldist);
	ray->drawstart = -ray->lineh / 2 + res_y / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineh / 2 + res_y / 2;
	if (ray->drawend >= res_y)
		ray->drawend = res_y - 1;
}

void	draw_col(t_mlxdt data)
{
	int	i;

	i = 0;
	while (i < data.ray.drawstart)
	{
		img_pix_put(&data.img, data.ray.x, i, data.info->ceil_color);
		i++;
	}
	while (i < data.ray.drawend)
	{
		if (data.ray.side == 1)
			img_pix_put(&data.img, data.ray.x, i, rgb_trad(0, 255, 255));
		else
			img_pix_put(&data.img, data.ray.x, i, rgb_trad(0, 127, 127));
		i++;
	}
	while (i < data.info->res_y)
	{
		img_pix_put(&data.img, data.ray.x, i, data.info->floor_color);
		i++;
	}
}

void	init_dirplane(t_ray *ray, t_minfo info)
{
	if (info.pos.dir == 'W')
		ray->dir_x = -1;
	else if (info.pos.dir == 'E')
		ray->dir_x = 1;
	else
		ray->dir_x = 0;
	if (info.pos.dir == 'S')
		ray->dir_y = 1;
	else if (info.pos.dir == 'N')
		ray->dir_y = -1;
	else
		ray->dir_y = 0;
	if (info.pos.dir == 'W')
		ray->plane_y = 0.66;
	else if (info.pos.dir == 'E')
		ray->plane_y = -0.66;
	else
		ray->plane_y = 0;
	if (info.pos.dir == 'S')
		ray->plane_x = 0.66;
	else if (info.pos.dir == 'N')
		ray->plane_x = -0.66;
	else
		ray->dir_y = 0;
}

void	ray_init(t_ray *ray, t_minfo info)
{
	ray->pos_x = info.pos.pos_x + 0.5;
	ray->pos_y = info.pos.pos_y + 0.5;
	init_dirplane(ray, info);
}
