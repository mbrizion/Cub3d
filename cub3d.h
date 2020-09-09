/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:44:34 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/09 05:36:47 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "mlx.h"
#include "libft/libft.h"
#include <stdio.h>
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

typedef struct s_music
{
	int pid;
}				t_music;

typedef struct s_sprite_pos
{
	double pos_x;
	double pos_y;
}				t_sprite_pos;

typedef struct s_sprite
{
	void 	*test_p;
	char	*ftexel_p;
	char 	*sprite_path;
	int		spriteScreenX;
	int		spriteHeight;
	int		spriteWidth;
	double	spriteX;
	double	spriteY;
	double	transformX;
	double	transformY;
	double	invDet;
	int		drawStartX;
	int		drawStartY;
	int		drawEndX;
	int		drawEndY;
	int		texX;
	int		texY;
	int		d;
	unsigned int color;
	unsigned char *color_c;
	double *wall_dist;
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
	void *text_f;
	void *text_c;
	void *ftexel_n;
	void *ftexel_e;
	void *ftexel_s;
	void *ftexel_w;
	void *ftexel_f;
	void *ftexel_c;
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
	int up;
	int down;
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
	t_list	*sprite_lst;
	double 	res_x;
	double 	res_y;
	double		pos_x;
	double		pos_y;
	char	spawn_dir;
	char 	*north_path;
	char 	*south_path;
	char 	*weast_path;
	char 	*east_path;
	char	*floor_rgb;
	char	*cieling_rgb;
	int		**map;
	int 	file_len;
	int		len_line;
	int 	rgb;
	int		bpp;
	int		size_line;
	int		floor_color;
	int		cieling_color;
	int		map_len;
}				t_info;

typedef struct s_game
{
	t_ptr 	ptr;
	t_info	info;
	t_move	move;
	t_tex	tex;
	t_music	music;
	double		plan_x;
	double		plan_y;
	double		dirX;
	double		dirY;
	int			fd;
	int			tmp;
	int			pad;
	unsigned int	filesize;
}				t_game;


int		parser(t_info *info, char *path);
int		ft_nbrlen(int n);
int		ft_atoi_cub(const char *str);
char	*ft_strjoin_charset(char const *s1, char const *s2, char charset);
int		check_map(t_info *info, char **map);
void 	raycasting(t_game *game);
void	raycasting2(t_game *game, t_ray *ray, int x, int y);
void	color_pixel(int x, int y, int color, t_game *game);
int 	keypress(int keycode, t_game *game);
int 	keyrelease(int keycode, t_game *game);
int		move(t_game *game);
int		get_rgb(char *str);
void 	error(int error_id);
int		ft_printf_error(char *str, ...);
size_t	strlen_spaces(const char *s);
int		sprite_raycast(t_game *game, double *wall_dist);
int		close_window(void);
int		map_checker(char **map, t_info *info);
char	*ft_strdup_len(const char *s1, int len);
int		screenshot(t_game *game);
int		free_all(t_game *game);
int		check_pos(int x, int y, t_info *info, char c);
char	**fill_map(char **map, t_info *info);
int	add_sprite(int i, int j, t_info *info);
int		get_map(t_info *info, char **map);
void	get_res(t_info *info, char *line);
void	north_tex(t_info *info, char *line, int i, int j);
void	south_tex(t_info *info, char *line, int i, int j);
void	weast_tex(t_info *info, char *line, int i, int j);
void	east_tex(t_info *info, char *line, int i, int j);
void	parser_loop(char *line, t_info *info, int j);
void	get_tex_path(t_info *info, char *line, char dir);
#endif
