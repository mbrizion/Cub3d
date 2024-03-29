/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 04:22:46 by user42            #+#    #+#             */
/*   Updated: 2020/09/17 03:25:57 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

void	ray_init(t_ray *ray, t_game *game, int x)
{
	ray->center = (2 * x / game->info.res_x) - 1;
	ray->len = 0;
	ray->pos_x = game->info.pos_x;
	ray->pos_y = game->info.pos_y;
	ray->dir_x = game->dir_x + game->plan_x * ray->center;
	ray->dir_y = game->dir_y + game->plan_y * ray->center;
	ray->map_x = (int)ray->pos_x;
	ray->map_y = (int)ray->pos_y;
	ray->delta_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y) /
									(ray->dir_x * ray->dir_x));
	ray->delta_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x) /
									(ray->dir_y * ray->dir_y));
	ray->hit = 0;
	game->ray_fc.dist_player = 0;
	game->ray_fc.current_dist = 0;
	game->ray_fc.weight = 0;
	game->ray_fc.current_floorx = 0;
	game->ray_fc.current_floory = 0;
	game->ray_fc.floor_xwall = 0;
	game->ray_fc.floor_ywall = 0;
	game->ray_fc.floor_tex_y = 0;
	game->ray_fc.floor_tex_x = 0;
	game->info.sprite.color = 0;
}
