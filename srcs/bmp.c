/*
** HEADER
*/

#include "../Includes/cub3d.h"

void conv_char(unsigned char *start, int size)
{
	start[0] = (unsigned char)(size);
	start[1] = (unsigned char)(size >> 8);
	start[2] = (unsigned char)(size >> 16);
	start[3] = (unsigned char)(size >> 24);
}


static int	fill_bmp(int fd, t_game *game)
{
	int x;
	int y;
	int		color;

	y = (int)game->info.res_x;
	while (y > 0)
	{
		x = 0;
		while (x < (int)game->info.res_y)
		{
			color = (*(int*)(game->ptr.fpixel_add + ((x + (y * (int)game->info.res_y)) * (game->info.bpp / 8))));
			if (write(fd, &color, 3) < 0)
				return (0);
			x++;
		}
		y--;
	}
	return (1);
}


int		screenshot(t_game *game)
{
	int fd;
	unsigned char header[54];
	unsigned int filesize;
	int tmp;
	int pad;


	pad = (4 - ((int)game->info.res_x * 3) % 4) % 4;
	filesize = 54 + (3 * ((int)game->info.res_x + pad) * (int)game->info.res_y);
	ft_bzero(header, 54);
	fd = open("save.bmp", O_CREAT | O_RDWR | O_TRUNC);
    header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	conv_char(header + 2, filesize);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	tmp = game->info.res_x;
	conv_char(header + 18, tmp);
	tmp = game->info.res_y;
	conv_char(header + 22, tmp);
	header[27] = (unsigned char)(1);
	header[28] = (unsigned char)(24);
	write(fd, header, 54);
	fill_bmp(fd, game);
	close (fd);
	return (0);
}