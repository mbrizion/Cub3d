/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:06:22 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/15 05:48:19 by user42           ###   ########.fr       */
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
	else if (info->spawn_dir)
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			error(-1);
	}
	return (0);
}

int			get_map(t_info *info)
{
	int		i;
	int		j;
	int		correct_len;
	int		save;

	i = 0;
	j = 0;
	save = info->map_start;
	if (!(info->map = malloc(sizeof (int *) * ((info->file_len - info->count) - info->map_start))))
		error (-4);
	correct_len = info->file_len - info->count;
	while (info->map_start < correct_len)
	{
		if (!(info->map[i] = malloc(sizeof(int) * ft_strlen(info->file[info->map_start]))))
			return (-1);
		while (j < (int)ft_strlen(info->file[info->map_start]))
		{
			if (info->file[info->map_start][j] == '2')
			{
				if (add_sprite(i, j, info) < 0)
					return (-1);
				info->map[i][j] = info->file[info->map_start][j] - '0';
			}
			if (!check_pos(i, j, info, info->file[info->map_start][j]))
				info->map[i][j] = info->file[info->map_start][j] - '0';
			j++;
		}
		j = 0;
		info->map_start++;
		i++;
	}
	info->map_start = save;
	return (0);
}
