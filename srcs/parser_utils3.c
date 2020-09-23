/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 04:07:50 by user42            #+#    #+#             */
/*   Updated: 2020/09/23 03:08:49 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			add_sprite(int i, int j, t_info *info)
{
	t_sprite_pos *sprite_pos;

	if ((sprite_pos = malloc(sizeof(t_sprite_pos))) == 0)
		return (-1);
	sprite_pos->pos_x = i + 0.5;
	sprite_pos->pos_y = j + 0.5;
	ft_lstadd_back(&info->sprite_lst, ft_lstnew(sprite_pos));
	return (0);
}

void		get_res(t_info *info, char *line)
{
	int i;

	i = 1;
	if (info->res_x || info->res_y)
		error2(-11);
	while (line[i])
	{
		if (line[i] && ft_isdigit(line[i]) && info->res_x == 0)
		{
			info->res_x = ft_atoi(&line[i]);
			i += ft_nbrlen((int)info->res_x);
			info->res_x = info->res_x > 2560 ? 2560 : info->res_x;
			info->res_x = info->res_x < 400 ? 400 : info->res_x;
		}
		if (line[i] && ft_isdigit(line[i]) && info->res_y == 0)
		{
			info->res_y = ft_atoi(&line[i]);
			info->res_y = info->res_y > 1440 ? 1440 : info->res_y;
			info->res_y = info->res_y < 200 ? 200 : info->res_y;
			break ;
		}
		i++;
	}
}

int			is_spawn(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int			conv_map(t_info *info)
{
	int		i;
	int		j;
	int		k;

	i = info->map_start;
	k = 0;
	while (i < info->file_len - info->map_start)
	{
		j = -1;
		while (++j < (int)ft_strlen(info->file[i]))
		{
			if (info->file[i][j] != ' ' && !is_spawn(info->file[i][j]))
				info->map[k][j] = info->file[i][j] - '0';
			else if (info->file[i][j] == ' ')
				info->map[k][j] = ' ';
			else if (is_spawn(info->file[i][j]))
				info->map[k][j] = 0;
		}
		i++;
		k++;
	}
	return (0);
}
