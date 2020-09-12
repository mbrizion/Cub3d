/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:06:22 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/12 04:13:50 by user42           ###   ########.fr       */
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

int			is_valid_char(char c)
{
	if (c == '0')
		return (1);
	else if (c == '1')
		return (1);
	else if (c == '2')
		return (1);
	else if (c == 'N')
		return (1);
	else if (c == 'S')
		return (1);
	else if (c == 'W')
		return (1);
	else if (c == 'E')
		return (1);
	return (0);
}

int			get_map_loop(int i, int j, char **map, t_info *info)
{
	if (!is_valid_char(map[i][j]))
		error(-3);
	if (map[i][j] == '2')
	{
		if (add_sprite(i, j, info) < 0)
			return (-1);
		info->map[i][j] = map[i][j] - '0';
	}
	if (!check_pos(i, j, info, map[i][j]))
		info->map[i][j] = map[i][j] - '0';
	return (0);
}

int			get_map(t_info *info, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!(info->map = malloc(sizeof(int *) * (info->map_len + 1))))
		return (-1);
	while (i < info->map_len + 1)
	{
		if (!(info->map[i] = malloc(sizeof(int) * ft_strlen(map[i]))))
			return (-1);
		while (j < (int)ft_strlen(map[i]))
		{
			if (get_map_loop(i, j, map, info) < 0)
				return (-1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
