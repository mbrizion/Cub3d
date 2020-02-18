/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:00:04 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/06 22:21:37 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int move(t_game *game)
{
	double old_dirX;
	double old_plan_x;

	if (game->move.forward)
	{
		if (game->info.map[(int)(game->info.pos_x + game->dirX * game->move.speed)][(int)game->info.pos_y] == 0)
			game->info.pos_x += game->dirX * game->move.speed;
		if (game->info.map[(int)game->info.pos_x][(int)(game->info.pos_y + game->dirY * game->move.speed)] == 0)
			game->info.pos_y += game->dirY * game->move.speed;
	}
	if (game->move.backward)
	{
		if (game->info.map[(int)(game->info.pos_x - game->dirX * game->move.speed)][(int)game->info.pos_y] == 0)
			game->info.pos_x -= game->dirX * game->move.speed;
		if (game->info.map[(int)game->info.pos_x][(int)(game->info.pos_y - game->dirY * game->move.speed)] == 0)
			game->info.pos_y -= game->dirY * game->move.speed;	
	}
	if (game->move.rot)
	{
		old_dirX = game->dirX;
		game->dirX = game->dirX * cos(-game->move.v_rot) - game->dirY * sin(-game->move.v_rot);
		game->dirY = old_dirX * sin(-game->move.v_rot) + game->dirY * cos(-game->move.v_rot);
		old_plan_x = game->plan_x;
		game->plan_x = game->plan_x * cos(-game->move.v_rot) - game->plan_y * sin(-game->move.v_rot);
		game->plan_y = old_plan_x * sin(-game->move.v_rot) + game->plan_y * cos(-game->move.v_rot);
	}
	if (game->move.right)
	{
		if (game->info.map[(int)(game->info.pos_x + game->plan_x * game->move.speed)][(int)game->info.pos_y] == 0)
			game->info.pos_x += game->plan_x * game->move.speed;
		if (game->info.map[(int)game->info.pos_x][(int)(game->info.pos_y + game->plan_y * game->move.speed)] == 0)
			game->info.pos_y += game->plan_y * game->move.speed;
	}
	if (game->move.left)
	{
		if (game->info.map[(int)(game->info.pos_x - game->plan_x * game->move.speed)][(int)game->info.pos_y] == 0)
			game->info.pos_x -= game->plan_x * game->move.speed;
		if (game->info.map[(int)game->info.pos_x][(int)(game->info.pos_y - game->plan_y * game->move.speed)] == 0)
			game->info.pos_y -= game->plan_y * game->move.speed;
	}
	raycasting(game);
	return (0);
}