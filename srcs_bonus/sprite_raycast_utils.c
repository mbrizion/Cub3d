/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 04:41:08 by user42            #+#    #+#             */
/*   Updated: 2020/09/16 05:15:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_sprite_loop(t_game *game, int y, int x)
{
	game->info.sprite.d = (y) * 256 - game->info.res_y * 128
	+ game->info.sprite.spriteHeight * 128;
	game->info.sprite.texY = ((game->info.sprite.d *
	game->tex.tex_h) / game->info.sprite.spriteHeight) / 256;
	game->info.sprite.color_c =
	(unsigned char *)&game->info.sprite.color;
	game->info.sprite.color_c[0] = game->info.sprite.ftexel_p
	[game->info.sprite.texY * game->tex.tex_len_size +
	game->info.sprite.texX * game->tex.tex_bpp / 8];
	game->info.sprite.color_c[1] = game->info.sprite.ftexel_p
	[game->info.sprite.texY * game->tex.tex_len_size +
	game->info.sprite.texX * game->tex.tex_bpp / 8 + 1];
	game->info.sprite.color_c[2] = game->info.sprite.ftexel_p
	[game->info.sprite.texY * game->tex.tex_len_size +
	game->info.sprite.texX * game->tex.tex_bpp / 8 + 2];
	if ((game->info.sprite.color & BLACK) != 0)
		ft_memcpy(&game->ptr.fpixel_add[(y *
		game->info.size_line + x * (game->info.bpp / 8))],
			&game->info.sprite.ftexel_p[(game->info.sprite.texY
			* game->tex.tex_len_size + game->info.sprite.texX
			* (game->info.bpp / 8))],
			game->tex.tex_bpp / 8);
}

void	sprite_calcul1(t_game *game, t_list *sprite)
{
	game->info.sprite.spriteX =
	((t_sprite_pos *)sprite->content)->pos_x - game->info.pos_x;
	game->info.sprite.spriteY =
	((t_sprite_pos *)sprite->content)->pos_y - game->info.pos_y;
	game->info.sprite.invDet =
	1.0 / (game->plan_x * game->dirY - game->dirX * game->plan_y);
	game->info.sprite.transformX = game->info.sprite.invDet * (game->dirY *
	game->info.sprite.spriteX - game->dirX * game->info.sprite.spriteY);
	game->info.sprite.transformY = game->info.sprite.invDet * (-game->plan_y
	* game->info.sprite.spriteX + game->plan_x * game->info.sprite.spriteY);
	game->info.sprite.spriteScreenX = (int)((game->info.res_x / 2) *
	(1 + (game->info.sprite.transformX / game->info.sprite.transformY)));
	game->info.sprite.spriteHeight =
	abs((int)(game->info.res_y / (game->info.sprite.transformY)));
	game->info.sprite.drawStartY =
	(-game->info.sprite.spriteHeight / 2) + (game->info.res_y / 2);
}

void	sprite_calcul2(t_game *game)
{
	if (game->info.sprite.drawStartY < 0)
		game->info.sprite.drawStartY = 0;
	game->info.sprite.drawEndY =
	(game->info.sprite.spriteHeight / 2) + (game->info.res_y / 2);
	if (game->info.sprite.drawEndY >= game->info.res_y)
		game->info.sprite.drawEndY = game->info.res_y - 1;
	game->info.sprite.spriteWidth =
	abs((int)(game->info.res_y / (game->info.sprite.transformY)));
	game->info.sprite.drawStartX =
	(-game->info.sprite.spriteWidth / 2) + game->info.sprite.spriteScreenX;
	if (game->info.sprite.drawStartX < 0)
		game->info.sprite.drawStartX = 0;
	game->info.sprite.drawEndX =
	(game->info.sprite.spriteWidth / 2) + game->info.sprite.spriteScreenX;
	if (game->info.sprite.drawEndX >= game->info.res_x)
		game->info.sprite.drawEndX = game->info.res_x - 1;
}
