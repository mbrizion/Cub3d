/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:19:18 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/16 03:33:08 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checker_part1(int i, int j, char **map)
{
	if (i == 0)
		error(-3);
	if (!map[i][j - 1])
		error(-3);
	if (map[i][j - 1] && map[i][j - 1] == ' ')
		error(-3);
	if (!map[i][j + 1])
		error(-3);
	if (map[i][j + 1] && map[i][j + 1] == ' ')
		error(-3);
	if (!map[i - 1][j - 1])
		error(-3);
	if (map[i - 1][j - 1] && map[i - 1][j - 1] == ' ')
		error(-3);
	if (!map[i - 1][j + 1])
		error(-3);
}

void	checker_part2(int i, int j, char **map)
{
	if (map[i - 1][j + 1] && map[i - 1][j + 1] == ' ')
		error(-3);
	if (!map[i - 1][j])
		error(-3);
	if (map[i - 1][j] && map[i - 1][j] == ' ')
		error(-3);
	if (!map[i + 1][j - 1])
		error(-3);
	if (map[i + 1][j - 1] && map[i + 1][j - 1] == ' ')
		error(-3);
	if (!map[i + 1][j + 1])
		error(-3);
	if (map[i + 1][j + 1] && map[i + 1][j + 1] == ' ')
		error(-3);
	if (!map[i + 1][j])
		error(-3);
	if (map[i + 1][j] && map[i + 1][j] == ' ')
		error(-3);
}

int		map_checker(t_info *info)
{
	int i;
	int j;
	int correct_len;
	char **tmp_map;

	i = 0;
	j = 0;
	if (!(tmp_map = malloc(sizeof(char *) * info->map_len)))
		error(-4);
	correct_len = info->file_len - info->count - info->map_start;
	while (i < info->map_len)
	{
		j = 0;
		tmp_map[i] = ft_strdup(info->file[info->map_start + i]);
		while (j < (int)ft_strlen(tmp_map[i]))
		{
			if (is_spawn(tmp_map[i][j]))
				tmp_map[i][j] = '0';
			j++;
		}
		i++;
	}
	i = 0;
	while (i < info->map_len)
	{
		j = 0;
		while (j < (int)ft_strlen(tmp_map[i]))
		{
			if (tmp_map[i][j] == '0' || tmp_map[i][j] == '2')
			{
				checker_part1(i, j, tmp_map);
				checker_part2(i, j, tmp_map);
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < info->map_len)
		free(tmp_map[i++]);
	free(tmp_map);
	if (!info->spawn_dir)
		error(-2);
	return (0);
}
