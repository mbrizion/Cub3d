/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:44:34 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/17 02:38:55 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include "get_next_line.h"
#include <math.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LA 123
# define KEY_RA 124
# define BLANC 0xE0E0E0
# define BLEU  0x607EBD
# define ROUGE 0xAD4B4B
# define JAUNE  0xD1C236
# define DestroyNotify 17
# define StructureNotifyMask 1L<<17
# define KeyPress 2
# define KeyPressMask 1L<<0
# define KeyRelease 3
# define KeyReleaseMask 1L<<1

typedef struct s_sprite
{
	int nb_sprite;
	double sprite_loc_x;
	double sprite_loc_y;
}				t_sprite;

typedef struct s_tex
{
	int tex_w;
	int tex_h;
	double wall_x;
	int tex_x;
	int tex_y;
	int tex_len_size;
	int tex_bpp;
	int tex_endian;
	void *text_n;
	void *text_e;
	void *text_s;
	void *text_w;
	void *ftexel_n;
	void *ftexel_e;
	void *ftexel_s;
	void *ftexel_w;
}				t_tex;

typedef struct s_ray
{
	int draw_start;
	int draw_end;
	int			hit;
	int			map_x;
	int			map_y;
	double 		pos_x;
	double 		pos_y;;
	double 		side_dist_x;
	double 		side_dist_y;
	double 		delta_dist_x;
	double 		delta_dist_y;
	double 		step_x;
	double 		step_y;
	int 		side;
	double		len;
	double		dir_x;
	double		dir_y;
	double		center;
	double		line_height;
}				t_ray;

typedef struct s_move
{
	int	forward;
	int	backward;
	int	left;
	int	right;
	double	rot;
	double	v_rot;
	double	speed;
}				t_move;

typedef struct s_ptr
{
	void *mlx_ptr;
	void *win_ptr;
	char *fpixel_add;
	void *buffer;
}				t_ptr;

typedef	struct s_info
{
	t_sprite sprite;
	double 	res_x;
	double 	res_y;
	double		pos_x;
	double		pos_y;
	char	spawn_dir;
	char 	*north_path;
	char 	*south_path;
	char 	*weast_path;
	char 	*east_path;
	char 	*sprite_path;
	char	*floor_rgb;
	char	*celling_rgb;
	int		**map;
	int 	file_len;
	int		len_line;
	int 	rgb;
	int		bpp;
	int		size_line;
	int		floor_color;
	int		celling_color;
	int		map_len;
}				t_info;

typedef struct s_game
{
	t_ptr 	ptr;
	t_info	info;
	t_move	move;
	t_tex	tex;
	double		plan_x;
	double		plan_y;
	double		dirX;
	double		dirY;
}				t_game;

int		parser(t_info *info, char *path);
int		ft_nbrlen(int n);
int		ft_atoi_cub(const char *str);
char	*ft_strjoin_charset(char const *s1, char const *s2, char charset);
int		charcmp(char c, char c2);
int		check_map(t_info info);
void 	raycasting(t_game *game);
void	color_pixel(int x, int y, int color, t_game *game);
int 	keypress(int keycode, t_game *game);
int 	keyrelease(int keycode, t_game *game);
int		move(t_game *game);
int		get_rgb(char *str);
int 	error(char c, int error_id);
int		ft_printf_error(char *str, ...);
size_t	strlen_spaces(const char *s);

#endif