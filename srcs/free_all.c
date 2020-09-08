/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 22:38:26 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/08 06:23:13 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	free_all(t_game *game)
{
	int i;

	i = game->info.map_len;
	free(game->info.north_path);
	free(game->info.south_path);
	free(game->info.weast_path);
	free(game->info.east_path);
	free(game->info.sprite.sprite_path);
	while (i >= 0)
	{
		free(game->info.map[i]);
		i--;
	}
	// close_window(game);
	return (0);
}
