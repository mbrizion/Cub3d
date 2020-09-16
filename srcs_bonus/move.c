/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:00:04 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/17 00:42:07 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	forward(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_x + game->dir_x
	* game->move.speed)][(int)game->info.pos_y] == 0)
		game->info.pos_x += game->dir_x * game->move.speed;
	if (game->info.map[(int)game->info.pos_x]
		[(int)(game->info.pos_y + game->dir_y * game->move.speed)] == 0)
		game->info.pos_y += game->dir_y * game->move.speed;
}

void	backward(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_x - game->dir_x
	* game->move.speed)][(int)game->info.pos_y] == 0)
		game->info.pos_x -= game->dir_x * game->move.speed;
	if (game->info.map[(int)game->info.pos_x]
		[(int)(game->info.pos_y - game->dir_y * game->move.speed)] == 0)
		game->info.pos_y -= game->dir_y * game->move.speed;
}

void	right(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_x + game->plan_x
	* game->move.speed)][(int)game->info.pos_y] == 0)
		game->info.pos_x += game->plan_x * game->move.speed;
	if (game->info.map[(int)game->info.pos_x]
		[(int)(game->info.pos_y + game->plan_y * game->move.speed)] == 0)
		game->info.pos_y += game->plan_y * game->move.speed;
}

void	left(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_x - game->plan_x
	* game->move.speed)][(int)game->info.pos_y] == 0)
		game->info.pos_x -= game->plan_x * game->move.speed;
	if (game->info.map[(int)game->info.pos_x]
		[(int)(game->info.pos_y - game->plan_y * game->move.speed)] == 0)
		game->info.pos_y -= game->plan_y * game->move.speed;
}

int		move(t_game *game)
{
	double old_dir_x;
	double old_plan_x;

	game->move.forward ? forward(game) : 0;
	game->move.backward ? backward(game) : 0;
	if (game->move.rot)
	{
		old_dir_x = game->dir_x;
		game->dir_x = game->dir_x * cos(-game->move.v_rot) - game->dir_y
		* sin(-game->move.v_rot);
		game->dir_y = old_dir_x * sin(-game->move.v_rot) + game->dir_y
		* cos(-game->move.v_rot);
		old_plan_x = game->plan_x;
		game->plan_x = game->plan_x * cos(-game->move.v_rot) - game->plan_y
		* sin(-game->move.v_rot);
		game->plan_y = old_plan_x * sin(-game->move.v_rot) + game->plan_y
		* cos(-game->move.v_rot);
	}
	game->move.right ? right(game) : 0;
	game->move.left ? left(game) : 0;
	raycasting(game);
	return (0);
}
