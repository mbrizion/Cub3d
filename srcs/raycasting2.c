/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 01:26:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/12 04:15:45 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hit(t_ray *ray, t_game *game)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->step_x == 1)
				ray->side = 0;
			else
				ray->side = 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->step_y == 1)
				ray->side = 2;
			else
				ray->side = 3;
		}
		if (game->info.map[ray->map_x][ray->map_y] == 1)
			ray->hit = 1;
	}
}

void	wall_texturing(t_ray *ray, t_game *game, int y, int x)
{
	game->tex.tex_y = (y * 2 - game->info.res_y + ray->line_height)
	* (game->tex.tex_h / 2) / ray->line_height;
	game->tex.tex_y = game->tex.tex_y < 0 ? 0 : game->tex.tex_y;
	game->tex.tex_y = game->tex.tex_y > game->tex.tex_h ? game->tex.tex_h : game->tex.tex_y;
	if (ray->side == 0)
		ft_memcpy(&game->ptr.fpixel_add[(y * game->info.size_line + x
		* (game->info.bpp / 8))], &game->tex.ftexel_s[(game->tex.tex_y *
		game->tex.tex_len_size + game->tex.tex_x * game->info.bpp / 8)],
		game->tex.tex_bpp / 8);
	else if (ray->side == 1)
		ft_memcpy(&game->ptr.fpixel_add[(y * game->info.size_line + x
		* (game->info.bpp / 8))], &game->tex.ftexel_n[(game->tex.tex_y *
		game->tex.tex_len_size + game->tex.tex_x * game->info.bpp / 8)],
		game->tex.tex_bpp / 8);
	else if (ray->side == 2)
		ft_memcpy(&game->ptr.fpixel_add[(y * game->info.size_line + x
		* (game->info.bpp / 8))], &game->tex.ftexel_e[(game->tex.tex_y *
		game->tex.tex_len_size + game->tex.tex_x * game->info.bpp / 8)],
		game->tex.tex_bpp / 8);
	else
		ft_memcpy(&game->ptr.fpixel_add[(y * game->info.size_line + x
		* (game->info.bpp / 8))], &game->tex.ftexel_w[(game->tex.tex_y *
		game->tex.tex_len_size + game->tex.tex_x * game->info.bpp / 8)],
		game->tex.tex_bpp / 8);
}

void	calculate(t_ray *ray, t_game *game, int x)
{
	if (ray->side == 0 || ray->side == 1)
	{
		ray->len = fabs((ray->map_x - ray->pos_x +
		(1 - ray->step_x) / 2) / ray->dir_x);
		game->tex.wall_x = ray->pos_y + ((ray->map_x - ray->pos_x +
		(1 - ray->step_x) / 2) / ray->dir_x) * ray->dir_y;
	}
	else
	{
		ray->len = fabs((ray->map_y - ray->pos_y +
		(1 - ray->step_y) / 2) / ray->dir_y);
		game->tex.wall_x = ray->pos_x + ((ray->map_y - ray->pos_y +
		(1 - ray->step_y) / 2) / ray->dir_y) * ray->dir_x;
	}
	game->info.sprite.wall_dist[x] = ray->len;
	game->tex.wall_x -= floor(game->tex.wall_x);
	game->tex.tex_x = (int)(game->tex.wall_x * game->tex.tex_w);
	ray->line_height = fabs(game->info.res_y / ray->len);
	ray->draw_start = (-ray->line_height / 2) + (game->info.res_y / 2);
	ray->draw_end = (ray->line_height / 2) + (game->info.res_y / 2);
}

void	raycasting2(t_game *game, t_ray *ray, int x, int y)
{
	hit(ray, game);
	calculate(ray, game, x);
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	if (ray->draw_end >= game->info.res_y)
		ray->draw_end = game->info.res_y;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		wall_texturing(ray, game, y, x);
		y++;
	}
	if (ray->draw_end < 0)
		ray->draw_end = game->info.res_y;
	y = ray->draw_end;
	while (y < game->info.res_y)
	{
		color_pixel(x, y, game->info.floor_color, game);
		color_pixel(x, game->info.res_y - y - 1,
		game->info.cieling_color, game);
		++y;
	}
}
