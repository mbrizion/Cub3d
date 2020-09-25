/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:44:34 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/24 03:25:43 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx.h"
# include "libft.h"
# include <stdio.h>
# include <math.h>

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_LA 65361
# define KEY_RA 65363
# define BLANC 0xE0E0E0
# define BLEU  0x607EBD
# define ROUGE 0xAD4B4B
# define JAUNE  0xD1C236
# define BLACK 0x00FFFFFF
# define N 78
# define S 83
# define E 69
# define W 87
# define P 80
# define ERROR 2

typedef struct	s_sprite_pos
{
	double pos_x;
	double pos_y;
}				t_sprite_pos;

typedef struct	s_sprite
{
	void			*test_p;
	char			*ftexel_p;
	char			*sprite_path;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	double			sprite_x;
	double			sprite_y;
	double			transform_x;
	double			transform_y;
	double			invdet;
	int				draw_s_x;
	int				draw_s_y;
	int				draw_e_x;
	int				draw_e_y;
	int				tex_x;
	int				tex_y;
	int				d;
	unsigned int	color;
	unsigned char	*color_c;
	double			*wall_dist;
}				t_sprite;

typedef struct	s_tex
{
	int			tex_w;
	int			tex_h;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	int			tex_len_size;
	int			tex_bpp;
	int			tex_endian;
	void		*text_n;
	void		*text_e;
	void		*text_s;
	void		*text_w;
	void		*text_f;
	void		*text_c;
	void		*ftexel_n;
	void		*ftexel_e;
	void		*ftexel_s;
	void		*ftexel_w;
	void		*ftexel_f;
	void		*ftexel_c;
}				t_tex;

typedef struct	s_ray
{
	int			draw_start;
	int			draw_end;
	int			hit;
	int			map_x;
	int			map_y;
	double		pos_x;
	double		pos_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		step_x;
	double		step_y;
	int			side;
	double		len;
	double		dir_x;
	double		dir_y;
	double		center;
	double		line_height;
}				t_ray;

typedef struct	s_move
{
	int			forward;
	int			backward;
	int			left;
	int			right;
	int			up;
	int			down;
	double		rot;
	double		v_rot;
	double		speed;
}				t_move;

typedef struct	s_ptr
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*fpixel_add;
	void		*buffer;
}				t_ptr;

typedef	struct	s_info
{
	t_sprite	sprite;
	t_list		*sprite_lst;
	double		res_x;
	double		res_y;
	double		pos_x;
	double		pos_y;
	char		spawn_dir;
	char		*north_path;
	char		*south_path;
	char		*weast_path;
	char		*east_path;
	char		*floor_rgb;
	char		*cieling_rgb;
	int			**map;
	int			file_len;
	int			len_line;
	int			rgb;
	int			bpp;
	int			size_line;
	int			floor_color;
	int			cieling_color;
	char		*line_buf;
	char		**file;
	int			file_index;
	int			map_start;
	int			buf;
	int			count;
	int			map_len;
	int			save;
	int			w;
	int			h;
}				t_info;

typedef struct	s_game
{
	t_ptr			ptr;
	t_info			info;
	t_move			move;
	t_tex			tex;
	double			plan_x;
	double			plan_y;
	double			dir_x;
	double			dir_y;
	int				fd;
	int				tmp;
	int				pad;
	unsigned int	filesize;
	int				y;
	int				x;
	int				img_size;
}				t_game;

int				parser(t_info *info, char *path, t_ptr *ptr);
int				ft_nbrlen(int n);
int				check_map(t_info *info, char **map);
void			raycasting(t_game *game, int save);
void			raycasting2(t_game *game, t_ray *ray, int x, int y);
void			color_pixel(int x, int y, int color, t_game *game);
int				keypress(int keycode, t_game *game);
int				keyrelease(int keycode, t_game *game);
int				move(t_game *game);
int				get_rgb(char *str);
void			error(int error_id);
void			error2(int error_id);
int				ft_printf_error(char *str, ...);
int				sprite_raycast(t_game *game, double *wall_dist);
int				close_window(void);
int				map_checker(t_info *info);
int				screenshot(t_game *game);
int				free_all(t_game *game, int save);
char			**fill_map(char **map, t_info *info);
int				add_sprite(int i, int j, t_info *info);
int				get_map(t_info *info);
void			get_res(t_info *info, char *line);
void			north_tex(t_info *info, char *line, int j);
void			south_tex(t_info *info, char *line, int j);
void			weast_tex(t_info *info, char *line, int j);
void			east_tex(t_info *info, char *line, int j);
void			get_tex_path(t_info *info, char *line, char dir);
void			ray_init(t_ray *ray, t_game *game, int x);
void			init_side_dist(t_ray *ray);
void			draw_sprite_loop(t_game *game, int y, int x);
void			sprite_calcul1(t_game *game, t_list *sprite);
void			sprite_calcul2(t_game *game);
void			load_tex(t_game *game);
int				is_spawn(char c);
int				conv_map(t_info *info);
void			check_path(t_info *info);
void			info_init(t_info *info);
int				all_info_init(t_info *info);
void			sprite_tex(t_info *info, char *line, int j);
void			ptr_init(t_game *game);
void			check_info(t_info *info);
int				copy_file(t_info *info);
#endif
