/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/04 05:05:44 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/22 04:21:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*reverse(char *str, int len, int size_line)
{
	int				i;
	unsigned char	*tmp;

	tmp = malloc(sizeof(unsigned char) * size_line);
	len--;
	i = 0;
	while (i < len - i)
	{
		ft_memcpy(tmp, str + i * size_line, size_line);
		ft_memcpy(str + i * size_line, str + (len * size_line - i * size_line),
		size_line);
		ft_memcpy(str + (len * size_line - i * size_line), tmp, size_line);
		i++;
	}
	free(tmp);
	return (str);
}

void	basic(unsigned char *header, unsigned int filesize)
{
	header[0] = 'B';
	header[1] = 'M';
	header[2] = filesize;
	header[3] = filesize >> 8;
	header[4] = filesize >> 16;
	header[5] = filesize >> 24;
	header[10] = 54;
	header[11] = 54 >> 8;
	header[12] = 54 >> 16;
	header[13] = 54 >> 24;
}

void	header_content(unsigned char *header, t_game *game)
{
	header[14] = 40;
	header[15] = 40 >> 8;
	header[16] = 40 >> 16;
	header[17] = 40 >> 24;
	header[18] = (int)game->info.res_x;
	header[19] = (int)game->info.res_x >> 8;
	header[20] = (int)game->info.res_x >> 16;
	header[21] = (int)game->info.res_x >> 24;
	header[22] = (int)game->info.res_y;
	header[23] = (int)game->info.res_y >> 8;
	header[24] = (int)game->info.res_y >> 16;
	header[25] = (int)game->info.res_y >> 24;
	header[26] = 1;
	header[27] = 1 >> 8;
	header[28] = game->info.bpp;
	header[29] = game->info.bpp >> 8;
}

int		write_header(unsigned char *header, t_game *game)
{
	int		fd;
	void	*buffer;

	if ((buffer = malloc(sizeof(unsigned char) * game->img_size)) == 0)
		return (-1);
	buffer = ft_memcpy(buffer, game->ptr.fpixel_add, game->img_size);
	buffer = reverse(buffer, (size_t)game->info.res_y, game->info.size_line);
	if ((fd = open("screenshot.bmp", O_WRONLY)) == -1)
		return (-1);
	write(fd, header, 54);
	write(fd, buffer, game->img_size);
	free(buffer);
	close(fd);
	return (0);
}

int		screenshot(t_game *game)
{
	int				fd;
	unsigned char	header[54];

	raycasting(game, 1);
	ft_bzero(header, 54);
	if ((fd = open("screenshot.bmp", O_CREAT, S_IRWXU)) == -1)
		return (-1);
	close(fd);
	if ((fd = open("screenshot.bmp", O_TRUNC)) == -1)
		return (-1);
	close(fd);
	game->img_size = (int)game->info.res_x *
	(int)game->info.res_y * (game->info.bpp / 8);
	game->filesize = game->img_size + 54;
	basic(header, game->filesize);
	header_content(header, game);
	return (write_header(header, game));
}
