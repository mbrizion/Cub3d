/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 01:33:14 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/16 03:03:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_rt_tools(t_game *game)
{
	if (game->tex.text_s && game->tex.text_n
	&& game->tex.text_w && game->tex.text_e && game->info.sprite.test_p)
	{
		free(game->info.sprite.wall_dist);
		mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_s);
		mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_n);
		mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_e);
		mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_w);
		mlx_destroy_image(game->ptr.mlx_ptr, game->info.sprite.test_p);
	}
}

void	color_pixel(int x, int y, int color, t_game *game)
{
	unsigned char *color_c;

	color_c = (unsigned char*)&color;
	game->ptr.fpixel_add[y * game->info.size_line + x *
	game->info.bpp / 8] = color_c[0];
	game->ptr.fpixel_add[y * game->info.size_line + x *
	game->info.bpp / 8 + 1] = color_c[1];
	game->ptr.fpixel_add[y * game->info.size_line + x *
	game->info.bpp / 8 + 2] = color_c[2];
}

void	load_tex(t_game *game)
{
	if (!(game->tex.text_n = mlx_xpm_file_to_image(game->ptr.mlx_ptr,
	game->info.north_path, &game->tex.tex_w, &game->tex.tex_h)))
		error(N);
	game->tex.ftexel_n = mlx_get_data_addr(game->tex.text_n,
	&game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->tex.text_s = mlx_xpm_file_to_image(game->ptr.mlx_ptr,
	game->info.south_path, &game->tex.tex_w, &game->tex.tex_h)))
		error(S);
	game->tex.ftexel_s = mlx_get_data_addr(game->tex.text_s,
	&game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->tex.text_w = mlx_xpm_file_to_image(game->ptr.mlx_ptr,
	game->info.weast_path, &game->tex.tex_w, &game->tex.tex_h)))
		error(W);
	game->tex.ftexel_w = mlx_get_data_addr(game->tex.text_w,
	&game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->tex.text_e = mlx_xpm_file_to_image(game->ptr.mlx_ptr,
	game->info.east_path, &game->tex.tex_w, &game->tex.tex_h)))
		error(E);
	game->tex.ftexel_e = mlx_get_data_addr(game->tex.text_e,
	&game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->info.sprite.test_p = mlx_xpm_file_to_image(game->ptr.mlx_ptr,
	game->info.sprite.sprite_path, &game->tex.tex_w, &game->tex.tex_h)))
		error(P);
	game->info.sprite.ftexel_p = mlx_get_data_addr(game->info.sprite.test_p,
	&game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
}

void	raycasting(t_game *game)
{
	int		y;
	int		x;
	int		endian;
	t_ray	ray;

	x = -1;
	y = 0;
	if (game->ptr.buffer)
		mlx_destroy_image(game->ptr.mlx_ptr, game->ptr.buffer);
	if (!(game->info.sprite.wall_dist = malloc(sizeof(double*)
	* game->info.res_x)))
		error(-4);
	game->ptr.buffer = mlx_new_image(game->ptr.mlx_ptr,
	game->info.res_x, game->info.res_y);
	game->ptr.fpixel_add = mlx_get_data_addr(game->ptr.buffer, &game->info.bpp,
	&game->info.size_line, &endian);
	while (++x < game->info.res_x)
	{
		ray_init(&ray, game, x);
		init_side_dist(&ray);
		raycasting2(game, &ray, x, y);
	}
	sprite_raycast(game, game->info.sprite.wall_dist);
	mlx_put_image_to_window(game->ptr.mlx_ptr, game->ptr.win_ptr,
	game->ptr.buffer, 0, 0);
}
