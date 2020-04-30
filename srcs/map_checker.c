/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:19:18 by mbrizion          #+#    #+#             */
/*   Updated: 2020/03/11 03:09:06 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void error(int error_id)
{
	if (error_id > 0)
		ft_printf_error("Error\nTexture not found (%c)\n", (char)error_id);
	else if (error_id == -1)
		ft_printf_error("Error\nMultiple spawnpoint\n");
	else if (error_id == -2)
		ft_printf_error("Error\nNo spawnpoint\n");
	else if (error_id == -3)
		ft_printf_error("Error\nMap error\n");
	exit(0);
}

int map_checker(char **map, t_info *info)
{
	int i;
	int j;
	int prev_len;

	i = 0;
	j = 0;

	while (i < info->map_len + 1)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == '2')
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
			j++;
		}
		i++;
	}

























	// if (!info->spawn_dir)
	// 	error(-2);
	// i = 0;
	// while (i < info->map_len)
	// 	printf ("%s\n", map[i++]);
	// printf ("%s\n", map[i]);
	// i = 0;
	// while (i < info->map_len)
	// {
	// 	if (map[i][ft_strlen(map[i]) - 1] != '1')
	// 		error(-3);
	// 	prev_len = (i == 0) ? ft_strlen(map[i]) : ft_strlen(map[i - 1]);
	// 	j = 0;
	// 	if (prev_len < ft_strlen(map[i]))
	// 	{
	// 		j = prev_len;
	// 		while (map[i][j] && j < ft_strlen(map[i]))
	// 		{
	// 			if (map[i][j] == '1' || map[i][j] == ' ')
	// 				j++;
	// 			else
	// 				error(-3);
	// 		}
	// 		j--;
	// 		if (map[i][j - 1] && map[i][j - 1] == '0')
	// 		{
	// 			if (map[i - 1] && map[i - 1][ft_strlen(map[i - 1])] != '1')
	// 				error(-3);
	// 			if (map[i - 1] && map[i - 1][ft_strlen(map[i - 1]) - 1] != '1')
	// 				error(-3);
	// 		}
	// 	}
	// 	else if (prev_len > ft_strlen(map[i]))
	// 	{
	// 		j = ft_strlen(map[i]);
	// 		while (map[i][j] && j < ft_strlen(map[i]))
	// 		{
	// 			if (map[i][j] == '1' || map[i][j] == ' ')
	// 				j++;
	// 			else
	// 				error(-3);
	// 		}
	// 	}
	// 	else if (prev_len == ft_strlen(map[i]))
	// 	{

	// 		if (map[i + 1] && ft_strlen(map[i]) > ft_strlen(map[i + 1]))
	// 		{
	// 			if (map[i][ft_strlen(map[i]) - 2] && map[i][ft_strlen(map[i]) - 2] == '0')
	// 			{
	// 				if (map[i + 1] && map[i + 1][ft_strlen(map[i + 1])] != '1')
	// 					error(-3);
	// 				if (map[i + 1] && map[i + 1][ft_strlen(map[i + 1]) - 1] != '1')
	// 					error(-3);
	// 			}
	// 		}
	// 	}
	// 	i++;
	// }
	// if (map[i][ft_strlen(map[i]) - 1] != '1')
	// 	error(-3);

	return (0);
}