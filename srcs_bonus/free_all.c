/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 22:38:26 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/16 03:46:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	free_all(t_game *game)
{
	int i;

	i = 0;
	free(game->info.north_path);
	free(game->info.south_path);
	free(game->info.weast_path);
	free(game->info.east_path);
	free(game->info.sprite.sprite_path);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_n);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_s);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_e);
	mlx_destroy_image(game->ptr.mlx_ptr, game->tex.text_w);
	mlx_destroy_image(game->ptr.mlx_ptr, game->info.sprite.test_p);
	// tex floor ciel
	mlx_destroy_window(game->ptr.mlx_ptr, game->ptr.win_ptr);
	while (i < game->info.map_len)
		free(game->info.map[i++]);
	free(game->info.map);
	free(game->ptr.mlx_ptr);
	ft_lstclear(&game->info.sprite_lst, &free);
	return (0);
}