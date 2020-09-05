/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 23:19:18 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/04 21:47:46 by mbrizion         ###   ########.fr       */
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
	else if (error_id == -7)
		ft_printf_error("Error\nFile name error\n");
	exit(0);
}

int map_checker(char **map, t_info *info)
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
	return (0);
}