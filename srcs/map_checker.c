/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:19:18 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/09 05:36:58 by mbrizion         ###   ########.fr       */
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

int		map_checker(char **map, t_info *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < info->map_len + 1)
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
	return (0);
}
