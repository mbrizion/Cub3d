/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 05:05:44 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/05 00:41:02 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		conv_char(unsigned char *start, int size)
{
	start[0] = (unsigned char)(size);
	start[1] = (unsigned char)(size >> 8);
	start[2] = (unsigned char)(size >> 16);
	start[3] = (unsigned char)(size >> 24);
}

static int	fill_bmp(int fd, t_game *game)
{
	int	x;
	int	y;
	int	color;

	y = (int)game->info.res_y;
	while (y > 0)
	{
		x = 0;
		while (x < (int)game->info.res_x)
		{
			color = (*(int*)(game->ptr.fpixel_add + ((x + (y *
			(int)game->info.res_x)) * (game->info.bpp / 8))));
			if (write(fd, &color, 3) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}

int			screenshot(t_game *game)
{
	unsigned char	header[54];

	game->pad = (4 - ((int)game->info.res_x * 3) % 4) % 4;
	game->filesize = 54 + (3 * ((int)game->info.res_x + game->pad)
	* (int)game->info.res_y);
	ft_bzero(header, 54);
	if ((game->fd = open("screenshot.bmp", O_TRUNC)) < 0)
		;
	if ((game->fd = open("screenshot.bmp", O_WRONLY | O_CREAT)) < 0)
		return (0);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	conv_char(header + 2, game->filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	game->tmp = game->info.res_x;
	conv_char(header + 18, game->tmp);
	game->tmp = game->info.res_y;
	conv_char(header + 22, game->tmp);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	write(game->fd, header, 54);
	fill_bmp(game->fd, game);
	close(game->fd);
	return (0);
}
