/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacktatoume <jacktatoume@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:20:20 by mbrizion          #+#    #+#             */
/*   Updated: 2020/04/12 20:29:38 by jacktatoume      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int		keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		free_all(game);
		exit(0);
	}
	else if (keycode == KEY_W)
		game->move.forward = 1;
	else if (keycode == KEY_S)
		game->move.backward = 1;
	else if (keycode == KEY_D)
		game->move.right = 1;
	else if (keycode == KEY_A)
		game->move.left = 1;
	else if (keycode == KEY_LA)
	{
		game->move.rot = 1;
		game->move.v_rot = -0.1;
	}
	else if (keycode == KEY_RA)
	{
		game->move.rot = 1;
		game->move.v_rot = 0.1;
	}
	return (0);
}

int		keyrelease(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
	{
		free_all(game);
		exit(0);
	}
	else if (keycode == KEY_W)
		game->move.forward = 0;
	else if (keycode == KEY_S)
		game->move.backward = 0;
	else if (keycode == KEY_D)
		game->move.right = 0;
	else if (keycode == KEY_A)
		game->move.left = 0;
	else if (keycode == KEY_LA)
	{
		game->move.rot = 0;
		game->move.v_rot = 0;
	}
	else if (keycode == KEY_RA)
	{
		game->move.rot = 0;
		game->move.v_rot = 0;
	}
	return (0);
}
