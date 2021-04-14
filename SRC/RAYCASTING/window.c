/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 14:14:37 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/12 16:03:47 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int		render(t_mlxdt *data)
{
	render_raycast(data);
	render_minimap(data);
	mlx_put_image_to_window(data->m_ptr, data->m_win, data->img.p_img, 0, 0);
	return (0);
}

int		window(t_minfo *info)
{
	t_mlxdt	data;

	data.m_ptr = mlx_init();
	data.m_win = mlx_new_window(data.m_ptr, info->res_x, info->res_y, "CUB3D");
	data.info = info;
	data.img.p_img = mlx_new_image(data.m_ptr, info->res_x, info->res_y);
	data.img.addr = mlx_get_data_addr(data.img.p_img, &data.img.bpp,
			&data.img.line_len, &data.img.endian);
	ray_init(&data.ray, *info);
	init_move(&data.move);
	printf("\n%f\n", data.move.speed);
	mlx_loop_hook(data.m_ptr, &render, &data);
	mlx_hook(data.m_win, 2, (1L << 0), &key_press, &data);
	mlx_hook(data.m_win, 3, (1L << 1), &key_release, &data);
	mlx_loop(data.m_ptr);
	free(data.m_ptr);
	return (0);
}
