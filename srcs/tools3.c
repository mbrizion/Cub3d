/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 01:10:04 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 00:05:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ptr_init(t_game *game)
{
	game->ptr.buffer = 0;
	game->ptr.mlx_ptr = mlx_init();
}

void	free_buf(char **buf)
{
	int i;

	i = 0;
	while (buf[i])
		free(buf[i++]);
	free(buf);
}

void	for_the_norm(char **tmp, int i)
{
	int j;

	j = 0;
	while (tmp[i][j++])
		if (ft_isalpha(tmp[i][j]))
			error(-9);
}
