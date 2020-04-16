/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacktatoume <jacktatoume@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:28:30 by mbrizion          #+#    #+#             */
/*   Updated: 2020/04/16 13:33:54 by jacktatoume      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int loop(t_game *game)
{
	if (game->move.forward == 1 || game->move.backward == 1 || game->move.right == 1 || game->move.left == 1 || game->move.v_rot != 0)
		move(game);
	return (0);
}

int		north_south(t_game *game)
{
	if (game->info.spawn_dir == 'N')
	{
		game->dirX = -1;
		game->dirY = 0;
		game->plan_x = 0;
		game->plan_y = 1;
		return (1);
	}
	else if (game->info.spawn_dir == 'S')
	{
		game->dirX = 1;
		game->dirY = 0;
		game->plan_x = 0;
		game->plan_y = -1;
		return (1);
	}
	return (0);
}

void	move_init(t_game *game)
{
	game->move.forward = 0;
	game->move.backward = 0;
	game->move.left = 0;
	game->move.right = 0;
	game->move.rot = 0;
	game->move.v_rot = 0;
	game->move.speed = 0.15;
	if (north_south(game));
	else if (game->info.spawn_dir == 'E')
	{
		game->dirX = 0;
		game->dirY = 1;
		game->plan_x = 1;
		game->plan_y = 0;
	}
	else
	{
		game->dirX = 0;
		game->dirY = -1;
		game->plan_x = -1;
		game->plan_y = 0;
	}
}

int 	main(int argc, char **argv)
{
	t_game game;
	
	if (argc < 2)
		return (0);
	if (!(ft_strnstr(((argv[1]) + ft_strlen(argv[1]) - 4), ".cub", 4)))
		error(-7);
	if (parser(&game.info, argv[1]) < 0)
		return (-1);
	move_init(&game);
	game.ptr.mlx_ptr = mlx_init();
	if ((game.ptr.win_ptr = mlx_new_window(game.ptr.mlx_ptr, game.info.res_x, game.info.res_y, "Cub3D")) == 0)
		return (-1);
	raycasting(&game);
	if (argv[2] && ft_strnstr(argv[2], "--save", 6))
		screenshot(&game);
	mlx_hook(game.ptr.win_ptr, DestroyNotify, StructureNotifyMask, close_window, 0);
	mlx_hook(game.ptr.win_ptr, KeyPress, KeyPressMask, &keypress, &game);
	mlx_hook(game.ptr.win_ptr, KeyRelease, KeyReleaseMask, &keyrelease, &game);
	mlx_loop_hook(game.ptr.mlx_ptr, &loop, &game);
	raycasting(&game);
	mlx_loop(game.ptr.mlx_ptr);
	return (0);
}
