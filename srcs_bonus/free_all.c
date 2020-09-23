/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 22:38:26 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/22 01:49:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	free_all1(t_game *game)
{
	free(game->info.north_path);
	free(game->info.south_path);
	free(game->info.weast_path);
	free(game->info.east_path);
	free(game->info.sprite.sprite_path);
	free(game->info.cieling_path);
	free(game->info.floor_path);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_n);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_s);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_e);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_w);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_c);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_f);
	mlx_destroy_image(game->ptr.mlx_ptr, game->info.sprite.test_p);
}

int		free_all(t_game *game, int save)
{
	int i;

	i = 0;
	free_all1(game);
	if (!save)
		mlx_destroy_window(game->ptr.mlx_ptr, game->ptr.win_ptr);
	if (save)
	{
		mlx_destroy_image(game->ptr.mlx_ptr, game->ptr.buffer);
		while (i < (game->info.file_len - game->info.count))
			free(game->info.file[i++]);
		free(game->info.file);
	}
	i = 0;
	while (i < game->info.map_len)
		free(game->info.map[i++]);
	free(game->info.map);
	free(game->ptr.mlx_ptr);
	ft_lstclear(&game->info.sprite_lst, &free);
	return (0);
}
