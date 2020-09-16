/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 00:43:52 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/17 00:34:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		sprite_tex_x(t_game *game, int x)
{
	game->info.sprite.tex_x =
			(int)(256 * (x - (-game->info.sprite.sprite_width / 2 +
			game->info.sprite.sprite_screen_x)) * game->tex.tex_w /
			game->info.sprite.sprite_width) / 256;
	return (game->info.sprite.draw_s_y);
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
		x = game->info.sprite.draw_s_x;
		while (x < game->info.sprite.draw_e_x)
		{
			y = sprite_tex_x(game, x);
			if (game->info.sprite.transform_y > 0 && x > 0 && x <
			game->info.res_x && game->info.sprite.transform_y < wall_dist[x])
			{
				while (y < game->info.sprite.draw_e_y)
					draw_sprite_loop(game, y++, x);
			}
			x++;
		}
		sprite = sprite->next;
	}
	return (1);
}
