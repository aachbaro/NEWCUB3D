/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:15:27 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/30 14:16:09 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	del_mapinfo(t_minfo *info)
{
	if (info->tex_n)
		free(info->tex_n);
	if (info->tex_s)
		free(info->tex_s);
	if (info->tex_w)
		free(info->tex_w);
	if (info->tex_e)
		free(info->tex_e);
	if (info->sprite)
		free(info->sprite);
	return (0);
}
