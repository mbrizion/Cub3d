/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 04:41:08 by user42            #+#    #+#             */
/*   Updated: 2020/09/17 00:46:00 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_sprite_loop(t_game *game, int y, int x)
{
	game->info.sprite.d = (y) * 256 - game->info.res_y * 128
	+ game->info.sprite.sprite_height * 128;
	game->info.sprite.tex_y = ((game->info.sprite.d *
	game->tex.tex_h) / game->info.sprite.sprite_height) / 256;
	game->info.sprite.color_c =
	(unsigned char *)&game->info.sprite.color;
	game->info.sprite.color_c[0] = game->info.sprite.ftexel_p
	[game->info.sprite.tex_y * game->tex.tex_len_size +
	game->info.sprite.tex_x * game->tex.tex_bpp / 8];
	game->info.sprite.color_c[1] = game->info.sprite.ftexel_p
	[game->info.sprite.tex_y * game->tex.tex_len_size +
	game->info.sprite.tex_x * game->tex.tex_bpp / 8 + 1];
	game->info.sprite.color_c[2] = game->info.sprite.ftexel_p
	[game->info.sprite.tex_y * game->tex.tex_len_size +
	game->info.sprite.tex_x * game->tex.tex_bpp / 8 + 2];
	if ((game->info.sprite.color & BLACK) != 0)
		ft_memcpy(&game->ptr.fpixel_add[(y *
		game->info.size_line + x * (game->info.bpp / 8))],
			&game->info.sprite.ftexel_p[(game->info.sprite.tex_y
			* game->tex.tex_len_size + game->info.sprite.tex_x
			* (game->info.bpp / 8))],
			game->tex.tex_bpp / 8);
}

void	sprite_calcul1(t_game *game, t_list *sprite)
{
	game->info.sprite.sprite_x =
	((t_sprite_pos *)sprite->content)->pos_x - game->info.pos_x;
	game->info.sprite.sprite_y =
	((t_sprite_pos *)sprite->content)->pos_y - game->info.pos_y;
	game->info.sprite.invdet =
	1.0 / (game->plan_x * game->dir_y - game->dir_x * game->plan_y);
	game->info.sprite.transform_x = game->info.sprite.invdet * (game->dir_y *
	game->info.sprite.sprite_x - game->dir_x * game->info.sprite.sprite_y);
	game->info.sprite.transform_y = game->info.sprite.invdet * (-game->plan_y
	* game->info.sprite.sprite_x + game->plan_x * game->info.sprite.sprite_y);
	game->info.sprite.sprite_screen_x = (int)((game->info.res_x / 2) *
	(1 + (game->info.sprite.transform_x / game->info.sprite.transform_y)));
	game->info.sprite.sprite_height =
	abs((int)(game->info.res_y / (game->info.sprite.transform_y)));
	game->info.sprite.draw_s_y =
	(-game->info.sprite.sprite_height / 2) + (game->info.res_y / 2);
}

void	sprite_calcul2(t_game *game)
{
	if (game->info.sprite.draw_s_y < 0)
		game->info.sprite.draw_s_y = 0;
	game->info.sprite.draw_e_y =
	(game->info.sprite.sprite_height / 2) + (game->info.res_y / 2);
	if (game->info.sprite.draw_e_y >= game->info.res_y)
		game->info.sprite.draw_e_y = game->info.res_y - 1;
	game->info.sprite.sprite_width =
	abs((int)(game->info.res_y / (game->info.sprite.transform_y)));
	game->info.sprite.draw_s_x =
	(-game->info.sprite.sprite_width / 2) + game->info.sprite.sprite_screen_x;
	if (game->info.sprite.draw_s_x < 0)
		game->info.sprite.draw_s_x = 0;
	game->info.sprite.draw_e_x =
	(game->info.sprite.sprite_width / 2) + game->info.sprite.sprite_screen_x;
	if (game->info.sprite.draw_e_x >= game->info.res_x)
		game->info.sprite.draw_e_x = game->info.res_x - 1;
}
