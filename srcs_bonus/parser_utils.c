/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:06:22 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/09 03:19:08 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

char		**fill_map(char **map, t_info *info)
{
	int		i;
	char	**tmp;

	if (!(tmp = malloc(sizeof(char *) * (info->map_len + 1))))
		return (0);
	i = 0;
	while (i < info->map_len)
	{
		if (!(tmp[i] = malloc(sizeof(char) * info->len_line + 1)))
			return (0);
		ft_bzero(tmp[i], info->len_line + 1);
		ft_strlcpy(tmp[i], map[i], info->len_line + 1);
		i++;
	}
	if (!(tmp[i] = malloc(sizeof(char) * info->len_line + 1)))
		return (0);
	ft_bzero(tmp[i], info->len_line + 1);
	ft_strlcpy(tmp[i], map[i], info->len_line + 1);
	while (i)
		free(map[i--]);
	free(map);
	return (tmp);
}

int		add_sprite(int i, int j, t_info *info)
{
	t_sprite_pos *sprite_pos;

	if ((sprite_pos = malloc(sizeof(t_sprite_pos))) == 0)
		return (-1);
	sprite_pos->pos_x = i + 0.5;
	sprite_pos->pos_y = j + 0.5;
	ft_lstadd_back(&info->sprite_lst, ft_lstnew(sprite_pos));
	return (0);
}

int			get_map(t_info *info, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	info->map = malloc(sizeof(int *) * (info->map_len + 1));
	while (i < info->map_len + 1)
	{
		if (!(info->map[i] = malloc(sizeof(int) * ft_strlen(map[i]))))
			return (-1);
		while (j < (int)ft_strlen(map[i]))
		{
			if (map[i][j] == '2')
			{
				if (add_sprite(i, j, info) < 0)
					return (-1);
				info->map[i][j] = map[i][j] - '0';
			}
			if (!check_pos(i, j, info, map[i][j]))
				info->map[i][j] = map[i][j] - '0';
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void		get_res(t_info *info, char *line)
{
	int i;

	i = 1;
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
