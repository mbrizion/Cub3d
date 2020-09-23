/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:06:22 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/23 23:33:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			check_pos(int x, int y, t_info *info, char c)
{
	if (!info->spawn_dir && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
	{
		info->spawn_dir = c;
		info->pos_x = x + 0.2;
		info->pos_y = y + 0.2;
		info->map[x][y] = 0;
		return (1);
	}
	else if (info->spawn_dir && all_info_init(info))
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			error(-1);
	}
	return (0);
}

int			get_map_loop(t_info *info, int i, int j)
{
	if (info->file[info->map_start][j] == '2')
	{
		if (add_sprite(i, j, info) < 0)
			return (0);
		info->map[i][j] = info->file[info->map_start][j] - '0';
	}
	if (!check_pos(i, j, info, info->file[info->map_start][j]))
		info->map[i][j] = info->file[info->map_start][j] - '0';
	return (1);
}

int			get_map(t_info *info)
{
	int		i;
	int		j;
	int		correct_len;

	i = 0;
	info->save = info->map_start;
	if (!(info->map = malloc(sizeof(int *)
	* ((info->file_len - info->map_start) + 1))))
		error(-4);
	correct_len = info->file_len - info->map_start;
	while (i < correct_len + 1)
	{
		j = 0;
		if (!(info->map[i] = malloc(sizeof(int)
		* ft_strlen(info->file[info->map_start]))))
			error(-4);
		while (j < (int)ft_strlen(info->file[info->map_start]))
			if (!(get_map_loop(info, i, j++)))
				return (-1);
		info->map_start++;
		i++;
	}
	info->map_len = info->map_start - info->save;
	info->map_start = info->save;
	return (0);
}

void		get_tex_path(t_info *info, char *line, char dir)
{
	int i;
	int j;

	i = 2;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	j = i + 2;
	if (dir == 'N')
		north_tex(info, line, j);
	else if (dir == 'S')
		south_tex(info, line, j);
	else if (dir == 'W')
		weast_tex(info, line, j);
	else if (dir == 'E')
		east_tex(info, line, j);
	else if (dir == 'P' && !info->sprite.sprite_path)
		sprite_tex(info, line, j);
}

void		check_info(t_info *info)
{
	if (!info->north_path || !info->south_path || !info->east_path
	|| !info->weast_path || !info->sprite.sprite_path)
		error(-5);
	if (!info->res_x || !info->res_y)
		error(-8);
}
