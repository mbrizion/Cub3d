/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 04:41:24 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 04:10:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		info_init(t_info *info)
{
	info->file_len = 0;
	info->map_len = 0;
	info->len_line = 0;
	info->spawn_dir = '\0';
	info->res_x = 0;
	info->res_y = 0;
	info->pos_x = 0;
	info->pos_y = 0;
	info->north_path = 0;
	info->south_path = 0;
	info->east_path = 0;
	info->weast_path = 0;
	info->floor_rgb = 0;
	info->cieling_rgb = 0;
	info->sprite.sprite_path = 0;
	info->sprite_lst = 0;
	info->floor_color = -1;
	info->cieling_color = -1;
	info->file_index = 0;
}

int			all_info_init(t_info *info)
{
	if (info->res_x && info->res_y && info->north_path
	&& info->south_path && info->east_path
	&& info->weast_path && info->floor_color != -1
	&& info->cieling_color != -1 && info->sprite.sprite_path)
		return (1);
	return (0);
}
