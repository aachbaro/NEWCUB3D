/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 13:18:08 by aachbaro          #+#    #+#             */
/*   Updated: 2021/04/12 12:52:00 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <mlx.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# define K_ESCAPE 53
# define K_LEFT 123
# define K_RIGHT 124
# define K_W 13
# define K_S 1
# define K_A 0
# define K_D 2

typedef struct		s_inipos
{
	int				pos_x;
	int				pos_y;
	char			dir;
}					t_inipos;

typedef struct		s_minfo
{
	long long		res_x;
	long long		res_y;
	int				floor_color;
	int				ceil_color;
	unsigned int	map_x;
	unsigned int	map_y;
	char			*tex_n;
	char			*tex_s;
	char			*tex_w;
	char			*tex_e;
	char			*sprite;
	char			**map;
	t_inipos		pos;
}					t_minfo;

typedef struct		s_img
{
  void				*p_img;
  char				*addr;
  int				bpp;
  int				line_len;
  int				endian;
}					t_img;

typedef struct		s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			raydir_x;
	double			raydir_y;
	double			camera_x;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineh;
	int				drawstart;
	int				drawend;
	int				x;
}					t_ray;

typedef struct		s_move
{
	int				forward;
	int				back;
	int				left;
	int				right;
	int				rotate_left;
	int				rotate_right;
	double			speed;
	double			rotation;
}					t_move;

typedef struct		s_mlxdt
{
	void			*m_ptr;
	void			*m_win;
	t_img			img;
	t_minfo			*info;
	t_ray			ray;
	t_move			move;
}					t_mlxdt;

/* PARCING */
int					get_info(int *fd, t_minfo *map, char *file);
int					texture_parcing(char *line, t_minfo *map);
int					check_border(char **tab, int x, int y);
long long			ft_ultratoi(const char *str);
int					check_res(char **line);
int					set_pos(t_minfo *info, int y, int x);
int					error_spec(int n);
int					check_mapinfo(t_minfo info);
int					check_comma(char *str);
char				**get_indic_tab(void);
int					get_parcer_tab(int (***f)(char **, t_minfo *));
int					check_rgb(char **rgb);
int					rgb_trad(int r, int g, int b);
int					get_north(char **line, t_minfo *info);
int					get_res(char **line, t_minfo *info);
int					get_south(char **line, t_minfo *info);
int					get_west(char **line, t_minfo *info);
int					get_east(char **line, t_minfo *info);
int					get_sprite(char **line, t_minfo *info);
int					get_floor(char **line, t_minfo *info);
int					get_ceil(char **line, t_minfo *info);
int					get_map(int *fd, char **line, t_minfo *info, char *file);
int					get_map_size(int *fd, char *line, t_minfo *info);
int					fill_mapline(char *line, t_minfo *info, int y);
int					check_maptab(t_minfo *info);
int					check_mspaces(char **tab, int x, int y);
int					is_map_line(char *line);

/* UTILS */
int					get_pos_tab(char *str, char **tab);
int					tab_len(char **tab);
int					get_pos(char *str, char c);
void				set_minfo(t_minfo *minfo);
int					del_strtab(char **tab);
int					del_mapinfo(t_minfo *info);

/* RAYCASTING */
void				img_pix_put(t_img *img, int x, int y, int color);
int					handle_no_event(void *data);
int					render(t_mlxdt *data);
int					window(t_minfo *info);
void				render_minimap(t_mlxdt *data);
void				render_raycast(t_mlxdt *data);
void				ray_init(t_ray *ray, t_minfo info);
void				init_raycast(t_mlxdt *data);
void				init_delta(t_ray *ray);
void				init_sidedist(t_ray *ray);
void				inc_sidedist(t_ray *ray, char **map);
void				get_perpwalldist(t_ray *ray, int res_y);
void				draw_col(t_mlxdt data);

/* MOVES */

void				init_move(t_move *move);
void				move_forward_back(t_mlxdt *data);
void				move_left_right(t_mlxdt *data);
void				rotate_right_left(t_mlxdt *data);
void				rotate_left(t_mlxdt *data, double olddir_x);
int					key_press(int keysym, t_mlxdt *data);
int 				key_release(int keysym, t_mlxdt *data);


#endif
