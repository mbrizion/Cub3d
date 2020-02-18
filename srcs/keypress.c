/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keypress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 05:03:39 by mbrizion          #+#    #+#             */
/*   forwarddated: 2020/02/05 16:04:43 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int 	keypress(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit (0);
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

int 	keyrelease(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit (0);
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