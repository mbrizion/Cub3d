/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:19:18 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/15 05:50:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checker_part1(int i, int j, int **map)
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

void	checker_part2(int i, int j, int **map)
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

int		map_checker(int **map, t_info *info)
{
	int i;
	int j;
	int correct_len;

	i = 0;
	j = 0;
	correct_len = info->file_len - info->count - info->map_start;
	while (i < correct_len + 1)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '2')
			{
				checker_part1(i, j, map);
				checker_part2(i, j, map);
			}
			j++;
		}
		i++;
	}
	if (!info->spawn_dir)
		error(-2);
	return (0);
}
