/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 12:31:17 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/12 14:26:07 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	key_press(int keysym, t_mlxdt *data)
{
	if (keysym == K_W)
		data->move.forward = 1;
	else if (keysym == K_S)
		data->move.back = 1;
	else if (keysym == K_A)
		data->move.left = 1;
	else if (keysym == K_D)
		data->move.right = 1;
	else if (keysym == K_LEFT)
		data->move.rotate_left = 1;
	else if (keysym == K_RIGHT)
		data->move.rotate_right = 1;
	return (0);
}

int	key_release(int keysym, t_mlxdt *data)
{
	if (keysym == K_W)
		data->move.forward = 0;
	else if (keysym == K_S)
		data->move.back = 0;
	else if (keysym == K_A)
		data->move.left = 0;
	else if (keysym == K_D)
		data->move.right = 0;
	else if (keysym == K_LEFT)
		data->move.rotate_left = 0;
	else if (keysym == K_RIGHT)
		data->move.rotate_right = 0;
	else if (keysym == K_ESCAPE)
	{
		mlx_destroy_window(data->m_ptr, data->m_win);
		data->m_win = NULL;
		exit(0);
	}
	return (0);
}
