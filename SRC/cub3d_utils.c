/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 14:09:24 by aachbaro          #+#    #+#             */
/*   Updated: 2021/03/30 14:15:23 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		get_pos_tab(char *str, char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		if (!(ft_strncmp(tab[i], str, ft_strlen(str) + 1)))
			return (i);
		i++;
	}
	return (-1);
}

int		tab_len(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int		get_pos(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	if (str[i] == 0)
		return (-1);
	return (i);
}

void	set_minfo(t_minfo *minfo)
{
	minfo->res_x = -1;
	minfo->res_y = -1;
	minfo->floor_color = -1;
	minfo->ceil_color = -1;
	minfo->map_x = 0;
	minfo->map_y = 0;
	minfo->tex_n = NULL;
	minfo->tex_s = NULL;
	minfo->tex_w = NULL;
	minfo->tex_e = NULL;
	minfo->sprite = NULL;
	minfo->pos.pos_x = -1;
	minfo->pos.pos_y = -1;
	minfo->pos.dir = 0;
}

int		del_strtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}
