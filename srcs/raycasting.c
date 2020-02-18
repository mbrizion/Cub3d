/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 01:33:14 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/12 15:26:16 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	color_pixel(int x, int y, int color, t_game *game)
{
	unsigned char *color_c;
	
	color_c = (unsigned char*)&color;
	game->ptr.fpixel_add[y * game->info.size_line + x * game->info.bpp / 8] = color_c[0];
	game->ptr.fpixel_add[y * game->info.size_line + x * game->info.bpp / 8 + 1] = color_c[1];
	game->ptr.fpixel_add[y * game->info.size_line + x * game->info.bpp / 8 + 2] = color_c[2];
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
	ray->delta_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y) / (ray->dir_x * ray->dir_x));
	ray->delta_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x) / (ray->dir_y * ray->dir_y));
	ray->hit = 0;
}

int load_tex(t_game *game)
{
	int res_w;
	int res_h;
	
	if (!(game->tex.text_n = mlx_xpm_file_to_image(game->ptr.mlx_ptr, game->info.north_path, &game->tex.tex_w, &game->tex.tex_h)))
		return (error('N', 0));
	game->tex.ftexel_n = mlx_get_data_addr(game->tex.text_n, &game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->tex.text_s = mlx_xpm_file_to_image(game->ptr.mlx_ptr, game->info.south_path, &game->tex.tex_w, &game->tex.tex_h)))
		return (error('S', 0));
	game->tex.ftexel_s = mlx_get_data_addr(game->tex.text_s, &game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->tex.text_w = mlx_xpm_file_to_image(game->ptr.mlx_ptr, game->info.weast_path, &game->tex.tex_w, &game->tex.tex_h)))
		return (error('W', 0));
	game->tex.ftexel_w = mlx_get_data_addr(game->tex.text_w, &game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	if (!(game->tex.text_e = mlx_xpm_file_to_image(game->ptr.mlx_ptr, game->info.east_path, &game->tex.tex_w, &game->tex.tex_h)))
		return (error('E', 0));
	game->tex.ftexel_e = mlx_get_data_addr(game->tex.text_e, &game->tex.tex_bpp, &game->tex.tex_len_size, &game->tex.tex_endian);
	return (1);
}

void raycasting(t_game *game)
{
	int y;
	int x;
	int endian;

	int rgb;
	t_ray ray;

	x = 0;
	y = 0;
	if (!load_tex(game))
		exit(0);
	game->ptr.buffer = mlx_new_image(game->ptr.mlx_ptr, game->info.res_x, game->info.res_y);
	game->ptr.fpixel_add = mlx_get_data_addr(game->ptr.buffer, &game->info.bpp, &game->info.size_line, &endian);
	while (x < game->info.res_x)
	{
		ray_init(&ray, game, x);
		if (ray.dir_x < 0)
		{
			ray.step_x = -1;
			ray.side_dist_x = (ray.pos_x - ray.map_x) * ray.delta_dist_x;
		}
		else
		{
			ray.step_x = 1;
			ray.side_dist_x = (ray.map_x + 1.0 - ray.pos_x) * ray.delta_dist_x;
		}
		if (ray.dir_y < 0)
		{
			ray.step_y = -1;
			ray.side_dist_y = (ray.pos_y - ray.map_y) * ray.delta_dist_y;
		}
		else
		{
			ray.step_y = 1;
			ray.side_dist_y = (ray.map_y + 1.0 - ray.pos_y) * ray.delta_dist_y;
		}
		while (ray.hit == 0)
		{
			if (ray.side_dist_x < ray.side_dist_y) 
			{
				ray.side_dist_x += ray.delta_dist_x;
				ray.map_x += ray.step_x;
				if (ray.step_x == 1)
				 	ray.side = 0;
				else
					ray.side = 1;
			}
			else
			{
				ray.side_dist_y += ray.delta_dist_y;
				ray.map_y += ray.step_y;
				if (ray.step_y == 1)
					ray.side = 2;
				else
					ray.side = 3;
			}
			if (game->info.map[ray.map_x][ray.map_y] > 0)
				ray.hit = 1;
		}
		if (ray.side == 0 || ray.side == 1)
		{
			ray.len = fabs((ray.map_x - ray.pos_x + (1 - ray.step_x) / 2) / ray.dir_x);
			game->tex.wall_x = ray.pos_y + ((ray.map_x - ray.pos_x + (1 - ray.step_x) / 2) / ray.dir_x) * ray.dir_y;
		}
		else
		{
			ray.len = fabs((ray.map_y - ray.pos_y + (1 - ray.step_y) / 2) / ray.dir_y);
			game->tex.wall_x = ray.pos_x + ((ray.map_y - ray.pos_y + (1 - ray.step_y) / 2) / ray.dir_y) * ray.dir_x;
		}
		game->tex.wall_x -= floor(game->tex.wall_x);
		game->tex.tex_x = (int)(game->tex.wall_x * game->tex.tex_w);
		ray.line_height = fabs(game->info.res_y / ray.len);
		ray.draw_start = -ray.line_height / 2 + game->info.res_y / 2;
		ray.draw_end = ray.line_height / 2 + game->info.res_y / 2;
		if (ray.draw_start < 0)
			ray.draw_start = 0;
		if (ray.draw_end >= game->info.res_y)
			ray.draw_end = game->info.res_y;
		y = ray.draw_start;
		while (y < ray.draw_end)
		{
			game->tex.tex_y = (y * 2 - game->info.res_y + ray.line_height) * (game->tex.tex_h / 2) / ray.line_height;
			
			if (ray.side == 0) // SOUTH
				ft_memcpy(&game->ptr.fpixel_add[(y * game->info.size_line + x * game->info.bpp / 8)],
                        &game->tex.ftexel_s[(game->tex.tex_y * game->tex.tex_len_size + game->tex.tex_x * game->tex.tex_bpp / 8)],
                            game->tex.tex_bpp / 8);
				// color_pixel(x, y, BLANC, game);
			else if (ray.side == 1) // NORTH
				ft_memcpy(&game->ptr.fpixel_add[(y * game->info.size_line + x * game->info.bpp / 8)],
                        &game->tex.ftexel_n[(game->tex.tex_y * game->tex.tex_len_size + game->tex.tex_x * game->tex.tex_bpp / 8)],
                            game->tex.tex_bpp / 8);
				// color_pixel(x, y, BLEU, game);
			else if (ray.side == 2) //EAST
			ft_memcpy(&game->ptr.fpixel_add[(y * game->info.size_line + x * game->info.bpp / 8)],
                        &game->tex.ftexel_e[(game->tex.tex_y * game->tex.tex_len_size + game->tex.tex_x * game->tex.tex_bpp / 8)],
                            game->tex.tex_bpp / 8);
				// color_pixel(x, y, ROUGE, game);
			else // WEAST
			ft_memcpy(&game->ptr.fpixel_add[(y * game->info.size_line + x * game->info.bpp / 8)],
                        &game->tex.ftexel_w[(game->tex.tex_y * game->tex.tex_len_size + game->tex.tex_x * game->tex.tex_bpp / 8)],
                            game->tex.tex_bpp / 8);
				// color_pixel(x, y, JAUNE, game); 
			++y;
		}
		if (ray.draw_end < 0)
			ray.draw_end = game->info.res_y;
		y = ray.draw_end;
		while (y < game->info.res_y)
		{
			color_pixel(x, y, game->info.floor_color, game);
			color_pixel(x, game->info.res_y - y - 1, game->info.celling_color, game);
			++y;
		}
		++x;
	}
	mlx_put_image_to_window(game->ptr.mlx_ptr, game->ptr.win_ptr, game->ptr.buffer, 0, 0);
}