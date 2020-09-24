/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:19:18 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/24 05:44:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	checker_part1(int i, int j, char **map)
{
	if (i == 0 || j == 0)
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

void	get_map_only(t_info *info, char **tmp_map, int i)
{
	int j;

	j = 0;
	tmp_map[i] = malloc(sizeof(char *) * info->map_len);
	ft_bzero(tmp_map[i], info->map_len);
	ft_strlcpy(tmp_map[i], info->file[info->map_start + i], ft_strlen(info->file[info->map_start + i]) + 1);
	while (j < (int)ft_strlen(tmp_map[i]))
	{
		if (is_spawn(tmp_map[i][j]))
			tmp_map[i][j] = '0';
		j++;
	}
}

void	check_map_loop(char **tmp_map, int i)
{
	int j;

	j = 0;
	while (j < (int)ft_strlen(tmp_map[i]))
	{
		if (tmp_map[i][j] == '0' || tmp_map[i][j] == '2')
		{
			checker_part1(i, j, tmp_map);
			checker_part2(i, j, tmp_map);
		}
		else if (tmp_map[i][j] != '1' && tmp_map[i][j] != 'N'
		&& tmp_map[i][j] != 'S' && tmp_map[i][j] != 'E' && tmp_map[i][j] != 'W'
		&& tmp_map[i][j] != '0' && tmp_map[i][j] != '2' && tmp_map[i][j] != ' '
		&& tmp_map[i][j] != '\t')
			error(-3);
		j++;
	}
}

int		map_checker(t_info *info)
{
	int		i;
	int		j;
	char	**tmp_map;

	i = 0;
	j = 0;
	if (!(tmp_map = malloc(sizeof(char *) * info->map_len)))
		error(-4);
	while (i < info->map_len)
		get_map_only(info, tmp_map, i++);
	i = 0;
	while (i < info->map_len)
		check_map_loop(tmp_map, i++);
	i = 0;
	while (i < info->map_len)
		free(tmp_map[i++]);
	free(tmp_map);
	if (!info->spawn_dir)
		error(-2);
	return (0);
}
