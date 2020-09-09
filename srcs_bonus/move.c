/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:00:04 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/09 03:19:05 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	forward(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_x + game->dirX
	* game->move.speed)][(int)game->info.pos_y] == 0)
		game->info.pos_x += game->dirX * game->move.speed;
	if (game->info.map[(int)game->info.pos_x]
		[(int)(game->info.pos_y + game->dirY * game->move.speed)] == 0)
		game->info.pos_y += game->dirY * game->move.speed;
}

void	backward(t_game *game)
{
	if (game->info.map[(int)(game->info.pos_x - game->dirX
	* game->move.speed)][(int)game->info.pos_y] == 0)
		game->info.pos_x -= game->dirX * game->move.speed;
	if (game->info.map[(int)game->info.pos_x]
		[(int)(game->info.pos_y - game->dirY * game->move.speed)] == 0)
		game->info.pos_y -= game->dirY * game->move.speed;
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
		old_dir_x = game->dirX;
		game->dirX = game->dirX * cos(-game->move.v_rot) - game->dirY
		* sin(-game->move.v_rot);
		game->dirY = old_dir_x * sin(-game->move.v_rot) + game->dirY
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
