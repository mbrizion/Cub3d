/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 01:33:14 by mbrizion          #+#    #+#             */
/*   Updated: 2020/03/05 23:35:31 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	color_pixel(int x, int y, int color, t_game *game)
{
	unsigned char *color_c;

	color_c = (unsigned char*)&color;
	game->ptr.fpixel_add[y * game->info.size_line + x *
	game->info.bpp / 8] = color_c[0];
	game->ptr.fpixel_add[y * game->info.size_line + x *
	game->info.bpp / 8 + 1] = color_c[1];
	game->ptr.fpixel_add[y * game->info.size_line + x *
	game->info.bpp / 8 + 2] = color_c[2];
}

void	ray_init(t_ray *ray, t_game *game, int x)
{
	ray->center = (2 * x / game->info.res_x) - 1;
	ray->pos_x = game->info.pos_x;
	ray->pos_y = game->info.pos_y;
	ray->dir_x = game->dirX + game->plan_x * ray->center;
	ray->dir_y = game->dirY + game->plan_y * ray->center;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->delta_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y) /
	(ray->dir_x * ray->dir_x));
	ray->delta_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x) /
	(ray->dir_y * ray->dir_y));
	ray->hit = 0;
}

int		load_tex(t_game *game)
{
	if (!(game->tex.text_n = mlx_xpm_file_to_image(game->ptr.mlx_ptr,
	game->info.north_path, &game->tex.tex_w, &game->tex.tex_h)))
		error(78);
	game->tex.ftexel_n = mlx_get_data_addr(game->tex.text_n,
	&game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->tex.text_s = mlx_xpm_file_to_image(game->ptr.mlx_ptr,
	game->info.south_path, &game->tex.tex_w, &game->tex.tex_h)))
		error(83);
	game->tex.ftexel_s = mlx_get_data_addr(game->tex.text_s,
	&game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->tex.text_w = mlx_xpm_file_to_image(game->ptr.mlx_ptr,
	game->info.weast_path, &game->tex.tex_w, &game->tex.tex_h)))
		error(87);
	game->tex.ftexel_w = mlx_get_data_addr(game->tex.text_w,
	&game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->tex.text_e = mlx_xpm_file_to_image(game->ptr.mlx_ptr,
	game->info.east_path, &game->tex.tex_w, &game->tex.tex_h)))
		error(69);
	game->tex.ftexel_e = mlx_get_data_addr(game->tex.text_e,
	&game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	return (1);
}

void	init_side_dist(t_ray *ray)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (ray->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - ray->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (ray->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - ray->pos_y) * ray->delta_dist_y;
	}
}

void	raycasting(t_game *game)
{
	int		y;
	int		x;
	int		endian;
	t_ray	ray;

	x = 0;
	y = 0;
	if (!(game->info.sprite.wall_dist = malloc(sizeof(double*)
	* game->info.res_x)))
		return ;
	load_tex(game);
	game->ptr.buffer = mlx_new_image(game->ptr.mlx_ptr,
	game->info.res_x, game->info.res_y);
	game->ptr.fpixel_add = mlx_get_data_addr(game->ptr.buffer, &game->info.bpp,
	&game->info.size_line, &endian);
	while (x < game->info.res_x)
	{
		ray_init(&ray, game, x);
		init_side_dist(&ray);
		raycasting2(game, &ray, x, y);
		++x;
	}
	sprite_raycast(game, game->info.sprite.wall_dist);
	mlx_put_image_to_window(game->ptr.mlx_ptr, game->ptr.win_ptr,
	game->ptr.buffer, 0, 0);
	
	// *******************************
	// void *test_img;
	// int test_x;
	// int test_y;

	// test_img = mlx_new_image(game->ptr.mlx_ptr, game->info.res_x / 4, game->info.res_y / 4);
	// if (!(test_img = mlx_xpm_file_to_image(game->ptr.mlx_ptr,"./pics/life.xpm", &test_x, &test_y)))
	// 	printf ("Nop2\n");
	// mlx_put_image_to_window(game->ptr.mlx_ptr, game->ptr.win_ptr,test_img, 10, game->info.res_y - 100);

	// test_img = mlx_new_image(game->ptr.mlx_ptr, game->info.res_x, game->info.res_y);
	// if (!(test_img = mlx_xpm_file_to_image(game->ptr.mlx_ptr,"./pics/crosshair.xpm", &test_x, &test_y)))
	// 	printf ("Nop3\n");
	// mlx_put_image_to_window(game->ptr.mlx_ptr, game->ptr.win_ptr,test_img, game->info.res_x / 2, ((game->info.res_y / 2) - (50 / game->info.res_y)));
	// *************************************************
}
