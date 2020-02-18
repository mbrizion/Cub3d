/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 22:28:30 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/17 01:23:02 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int loop(t_game *game)
{
	if (game->move.forward == 1 || game->move.backward == 1 || game->move.right == 1 || game->move.left == 1 || game->move.v_rot != 0)
		move(game);
	return (0);
}

int		close_window(void)
{
	exit(0);
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
	if (game->info.spawn_dir == 'N')
	{
		game->dirX = -1;
		game->dirY = 0;
		game->plan_x = 0;
		game->plan_y = 1;
	}
	else if (game->info.spawn_dir == 'S')
	{
		game->dirX = 1;
		game->dirY = 0;
		game->plan_x = 0;
		game->plan_y = -1;
	}
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

int		get_rgb(char *str)
{
	char **tmp;
	int color;

	color = 0;
	tmp = ft_split(str, ',');
	color += ft_atoi(tmp[0]) << 16;
    color += ft_atoi(tmp[1]) << 8;
    color += ft_atoi(tmp[2]);
	free (tmp);
	return (color);
}

int 	main(int argc, char **argv)
{
	t_game game;
	int x = 0;
	int y = 0;
	char **str;
	int endian;
	parser(&game.info, argv[1]);
	move_init(&game);
	printf ("|%s|\n", game.info.north_path);
	game.ptr.mlx_ptr = mlx_init();
	if ((game.ptr.win_ptr = mlx_new_window(game.ptr.mlx_ptr, game.info.res_x, game.info.res_y, "Cub3D")) == 0)
		return (-1);
	mlx_hook(game.ptr.win_ptr, DestroyNotify, StructureNotifyMask, close_window, 0);
	mlx_hook(game.ptr.win_ptr, KeyPress, KeyPressMask, &keypress, &game);
	mlx_hook(game.ptr.win_ptr, KeyRelease, KeyReleaseMask, &keyrelease, &game);
	mlx_loop_hook(game.ptr.mlx_ptr, &loop, &game);
	raycasting(&game);
	mlx_loop(game.ptr.mlx_ptr);
	return (0);
}
