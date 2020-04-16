/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacktatoume <jacktatoume@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:43:52 by mbrizion          #+#    #+#             */
/*   Updated: 2020/04/16 14:36:29 by jacktatoume      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	sprite_raycast(t_game *game, double *wall_dist)
{
	int i;
	int y;
	int x;

	i = 0;
	game->info.sprite.color = 0;
	game->info.sprite.test_p = mlx_xpm_file_to_image(game->ptr.mlx_ptr, game->info.sprite.sprite_path, &game->tex.tex_w, &game->tex.tex_h);
	if (!(game->info.sprite.ftexel_p = mlx_get_data_addr(game->info.sprite.test_p , &game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian)))
		return (0);
	while (i < 1)
	{
		game->info.sprite.spriteX = game->info.sprite_pos.pos_x - game->info.pos_x;
		game->info.sprite.spriteY = game->info.sprite_pos.pos_y - game->info.pos_y;
	printf ("%f\n", game->info.sprite.spriteX);
	printf ("%f\n", game->info.sprite.spriteY);
		game->info.sprite.invDet = 1.0 / (game->plan_x * game->dirY - game->dirX * game->plan_y); 
		game->info.sprite.transformX = game->info.sprite.invDet * (game->dirY * game->info.sprite.spriteX - game->dirX * game->info.sprite.spriteY);
		game->info.sprite.transformY = game->info.sprite.invDet * (-game->plan_y * game->info.sprite.spriteX + game->plan_x * game->info.sprite.spriteY);
		game->info.sprite.spriteScreenX = (int)((game->info.res_x / 2) * (1 + (game->info.sprite.transformX / game->info.sprite.transformY)));
		game->info.sprite.spriteHeight = abs((int)(game->info.res_y / (game->info.sprite.transformY)));
		game->info.sprite.drawStartY = (-game->info.sprite.spriteHeight / 2) + (game->info.res_y / 2);
		if(game->info.sprite.drawStartY < 0)
			game->info.sprite.drawStartY = 0;
		game->info.sprite.drawEndY = (game->info.sprite.spriteHeight / 2) + (game->info.res_y / 2);
		if(game->info.sprite.drawEndY >= game->info.res_y)
			game->info.sprite.drawEndY = game->info.res_y - 1;

		game->info.sprite.spriteWidth = abs((int)(game->info.res_y / (game->info.sprite.transformY)));
		game->info.sprite.drawStartX = (-game->info.sprite.spriteWidth / 2) + game->info.sprite.spriteScreenX;
		if(game->info.sprite.drawStartX < 0)
			game->info.sprite.drawStartX = 0;
		game->info.sprite.drawEndX = (game->info.sprite.spriteWidth / 2) + game->info.sprite.spriteScreenX;
		if(game->info.sprite.drawEndX >= game->info.res_x)
			game->info.sprite.drawEndX = game->info.res_x - 1;
		x = game->info.sprite.drawStartX;
		while (x < game->info.sprite.drawEndX)
		{
			game->info.sprite.texX = (int)(256 * (x - (-game->info.sprite.spriteWidth / 2 + game->info.sprite.spriteScreenX)) * game->tex.tex_w / game->info.sprite.spriteWidth) / 256;
			y = game->info.sprite.drawStartY;
			if(game->info.sprite.transformY > 0 && x > 0 && x < game->info.res_x && game->info.sprite.transformY < wall_dist[x])
			{
				while (y < game->info.sprite.drawEndY)
				{
					game->info.sprite.d = (y) * 256 - game->info.res_y * 128 + game->info.sprite.spriteHeight * 128;
					game->info.sprite.texY = ((game->info.sprite.d * game->tex.tex_h) / game->info.sprite.spriteHeight) / 256;
					
					game->info.sprite.color_c = (unsigned char *)&game->info.sprite.color;


					game->info.sprite.color_c[0] = game->info.sprite.ftexel_p[game->info.sprite.texY * game->tex.tex_len_size + game->info.sprite.texX * game->tex.tex_bpp / 8];
					game->info.sprite.color_c[1] = game->info.sprite.ftexel_p[game->info.sprite.texY * game->tex.tex_len_size + game->info.sprite.texX * game->tex.tex_bpp / 8 + 1];
					game->info.sprite.color_c[2] = game->info.sprite.ftexel_p[game->info.sprite.texY * game->tex.tex_len_size + game->info.sprite.texX * game->tex.tex_bpp / 8 + 2];

					if((game->info.sprite.color & 0x00FFFFFF) != 0)
						ft_memcpy(&game->ptr.fpixel_add[(y * game->info.size_line + x * (game->info.bpp / 8))],
							&game->info.sprite.ftexel_p[(game->info.sprite.texY * game->tex.tex_len_size + game->info.sprite.texX * (game->info.bpp / 8))],
							game->tex.tex_bpp / 8);
					y++;
				}
			}
			x++;
		}
		i++;
		}
		return (1);
}