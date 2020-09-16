/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:43:52 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/16 05:15:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	sprite_sorter(t_list *lst, t_game *game)
{
	t_list *tmp;
	double sprite_dst;
	double tmp_dst;

	while (lst)
	{
		tmp = lst->next;
		while (tmp)
		{
			sprite_dst = (
			(game->info.pos_x - ((t_sprite_pos *)(lst->content))->pos_x) *
			(game->info.pos_x - ((t_sprite_pos *)(lst->content))->pos_x) +
			(game->info.pos_y - ((t_sprite_pos *)(lst->content))->pos_y) *
			(game->info.pos_y - ((t_sprite_pos *)(lst->content))->pos_y));
			tmp_dst = (
			(game->info.pos_x - ((t_sprite_pos *)(lst->content))->pos_x) *
			(game->info.pos_x - ((t_sprite_pos *)(tmp->content))->pos_x) +
			(game->info.pos_y - ((t_sprite_pos *)(tmp->content))->pos_y) *
			(game->info.pos_y - ((t_sprite_pos *)(tmp->content))->pos_y));
			if (tmp_dst > sprite_dst)
				ft_lstswap(lst, tmp);
			tmp = tmp->next;
		}
		lst = lst->next;
	}
}

int		for_the_norm(t_game *game, int x)
{
	game->info.sprite.texX =
			(int)(256 * (x - (-game->info.sprite.spriteWidth / 2 +
			game->info.sprite.spriteScreenX)) * game->tex.tex_w /
			game->info.sprite.spriteWidth) / 256;
	return (game->info.sprite.drawStartY);
}

int		sprite_raycast(t_game *game, double *wall_dist)
{
	int		y;
	int		x;
	t_list	*sprite;

	sprite_sorter(game->info.sprite_lst, game);
	sprite = game->info.sprite_lst;
	while (sprite)
	{
		sprite_calcul1(game, sprite);
		sprite_calcul2(game);
		x = game->info.sprite.drawStartX;
		while (x < game->info.sprite.drawEndX)
		{
			y = for_the_norm(game, x);
			if (game->info.sprite.transformY > 0 && x > 0 &&
			x < game->info.res_x && game->info.sprite.transformY < wall_dist[x])
			{
				while (y < game->info.sprite.drawEndY)
					draw_sprite_loop(game, y++, x);
			}
			x++;
		}
		sprite = sprite->next;
	}
	return (1);
}
