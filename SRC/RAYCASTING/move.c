/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:35:56 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/12 15:55:56 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_move(t_move *move)
{
	move->forward = 0;
	move->back = 0;
	move->left = 0;
	move->right = 0;
	move->rotate_left = 0;
	move->rotate_right = 0;
	move->speed = 0.15;
	move->rotation = 0.1;
}

void	move_forward_back(t_mlxdt *data)
{
	if (data->move.forward == 1)
	{
		if (data->info->map[(int)data->ray.pos_y][(int)(data->ray.pos_x +
					data->ray.dir_x * (data->move.speed * 2))] == '0')
			data->ray.pos_x += data->ray.dir_x * data->move.speed;
		if (data->info->map[(int)(data->ray.pos_y + data->ray.dir_y *
					(data->move.speed * 2))][(int)(data->ray.pos_x)] == '0')
			data->ray.pos_y += data->ray.dir_y * data->move.speed;
	}
	if (data->move.back == 1)
	{
		if (data->info->map[(int)(data->ray.pos_y)][(int)(data->ray.pos_x -
				data->ray.dir_x * (data->move.speed * 2))] == '0')
			data->ray.pos_x -= data->ray.dir_x * data->move.speed;
		if (data->info->map[(int)(data->ray.pos_y - (data->ray.dir_y *
						data->move.speed * 2))][(int)(data->ray.pos_x)] == '0')
			data->ray.pos_y -= data->ray.dir_y * data->move.speed;
	}
}

void	move_left_right(t_mlxdt *data)
{
	if (data->move.right == 1)
	{
		if (data->info->map[(int)data->ray.pos_y][(int)(data->ray.pos_x +
					data->ray.dir_y * (data->move.speed * 2))] == '0')
			data->ray.pos_x += data->ray.dir_y * data->move.speed;
		if (data->info->map[(int)(data->ray.pos_y - data->ray.dir_x *
					(data->move.speed * 2))][(int)data->ray.pos_x] == '0')
			data->ray.pos_y -= data->ray.dir_x * data->move.speed;
	}
	if (data->move.left == 1)
	{
		if (data->info->map[(int)data->ray.pos_y][(int)(data->ray.pos_x -
					data->ray.dir_y * (data->move.speed * 2))] == '0')
			data->ray.pos_x -= data->ray.dir_y * data->move.speed;
		if (data->info->map[(int)(data->ray.pos_y + data->ray.dir_x *
					(data->move.speed * 2))][(int)data->ray.pos_x] == '0')
			data->ray.pos_y += data->ray.dir_x * data->move.speed;
	}
}

void	rotate_right_left(t_mlxdt *data)
{
	double oldplane_x;
	double olddir_x;

	oldplane_x = data->ray.plane_x;
	olddir_x = data->ray.dir_x;
	if (data->move.rotate_right == 1)
	{
		data->ray.dir_x = data->ray.dir_x * cos(-data->move.rotation / 2) -
			data->ray.dir_y * sin(-data->move.rotation / 2);
		data->ray.dir_y = olddir_x * sin(-data->move.rotation / 2) +
			data->ray.dir_y * cos(-data->move.rotation / 2);
		data->ray.plane_x = data->ray.plane_x * cos(-data->move.rotation / 2)
			- data->ray.plane_y * sin(-data->move.rotation / 2);
		data->ray.plane_y = oldplane_x * sin(-data->move.rotation / 2) +
			data->ray.plane_y * cos(-data->move.rotation / 2);
	}
	rotate_left(data, olddir_x);
}

void	rotate_left(t_mlxdt *data, double olddir_x)
{
	double oldplanex;

	if (data->move.rotate_left == 1)
	{
		olddir_x = data->ray.dir_x;
		oldplanex = data->ray.plane_x;
		data->ray.dir_x = data->ray.dir_x * cos(data->move.rotation / 2) -
			data->ray.dir_y * sin(data->move.rotation / 2);
		data->ray.dir_y = olddir_x * sin(data->move.rotation / 2) + data->
			ray.dir_y * cos(data->move.rotation / 2);
		data->ray.plane_x = data->ray.plane_x * cos(data->move.rotation / 2) -
			data->ray.plane_y * sin(data->move.rotation / 2);
		data->ray.plane_y = oldplanex * sin(data->move.rotation / 2) +
			data->ray.plane_y * cos(data->move.rotation / 2);
	}
}
