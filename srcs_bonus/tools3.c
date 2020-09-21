/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 01:10:04 by user42            #+#    #+#             */
/*   Updated: 2020/09/18 01:17:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	ptr_init(t_game *game)
{
	game->ptr.buffer = 0;
	game->ptr.mlx_ptr = mlx_init();
}