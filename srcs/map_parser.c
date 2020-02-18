/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 03:37:38 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/17 02:36:42 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	check_spawn(int x, int y, t_info *info, char str)
{
	if (str == 'N' || str == 'S' || str == 'E' || str == 'W')
	{
		info->spawn_dir = str;
		info->pos_x = x;
		info->pos_y = y;
	}
}

int	get_map(t_info *info, char **map)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	info->map = malloc(sizeof(int *) * info->map_len);
	while (i < info->map_len)
	{
		info->map[i] = malloc(sizeof(int) * (strlen_spaces(map[i])));
		while (j < strlen_spaces(map[i]))
		{
			if (map[i][k])
			{
				check_spawn(i, j, info, map[i][j]);
				info->map[i][j] = ft_atoi(&map[i][k]);
				if (map[i][k] && map[i][k + 1] && map[i][k + 1] == ' ')
					k++;
				k++;
			}
			j++;
		}
		k = 0;
		j = 0;
		i++;
	}
	return (0);
}

void	get_res(t_info *info, char *line)
{
	int i;
	
	i = 1;
	while (line[i])
	{
		if (line[i] && ft_isdigit(line[i]) && info->res_x == 0)
		{
			info->res_x = ft_atoi(&line[i]);
			i += ft_nbrlen((int)info->res_x);
		}
		if (line[i] && ft_isdigit(line[i]) && info->res_y == 0)
		{
			info->res_y = ft_atoi(&line[i]);
			break ;
		}
		i++;
	}
}

void	get_tex_path(t_info *info, char *line, char dir)
{
	int i;
	int j;

	i = 2;
	while (line[i] && line[i] == ' ')
		i++;
	j = i;
	while (line[j] && line[j] != ' ')
		j++;
	if (dir == 'N')
	{
		info->north_path = malloc(sizeof(char) * ((j - i) + 1));
		ft_strlcpy(info->north_path, &line[i], ((j - i) + 1));
	}
	if (dir == 'S')
	{
		info->south_path = malloc(sizeof(char) * ((j - i) + 1));
		ft_strlcpy(info->south_path, &line[i], ((j - i) + 1));
	}
	else if (dir == 'W')
	{
		info->weast_path = malloc(sizeof(char) * ((j - i) + 1));
		ft_strlcpy(info->weast_path, &line[i], ((j - i) + 1));
	}
	else if (dir == 'E')
	{
		info->east_path = malloc(sizeof(char) * ((j - i) + 1));
		ft_strlcpy(info->east_path, &line[i], ((j - i) + 1));
	}
	else if (dir == 'P')
	{
		info->sprite_path = malloc(sizeof(char) * ((j - i) + 1));
		ft_strlcpy(info->sprite_path, &line[i], ((j - i) + 1));
	}
}

int	parser(t_info *info, char *path)
{
	char *line;
	int j;
	int ret;
	int fd;
	int i;
	char **tmp;

	info->map_len = 1;
	info->file_len = 1;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &line) > 0))
	{
		if (line[0] == '1')
			info->map_len++;
		info->file_len++;
	}
	close (fd);
	if (!(tmp = malloc(sizeof(char *) * info->map_len)))
		return (-1);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	line = 0;
	ret = 1;
	i = 0;
	info->sprite.nb_sprite = 0;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		j = 0;
		while (line[j])
		{
			while (line[j] && line[j] == ' ')
				j++;
			if (line[j] && !ft_strncmp("R", &line[j], 1))
				get_res(info, &line[j]);
			if (line[j] && !ft_strncmp("NO", &line[j], 2))
				get_tex_path(info, &line[j], 'N');
			if (line[j] && !ft_strncmp("SO", &line[j], 2))
				get_tex_path(info, &line[j], 'S');
			if (line[j] && !ft_strncmp("WE", &line[j], 2))
				get_tex_path(info, &line[j], 'W');
			if (line[j] && !ft_strncmp("EA", &line[j], 2))
				get_tex_path(info, &line[j], 'E');
			if (line[j] && !ft_strncmp("C", &line[j], 1))
				info->celling_color = get_rgb(&line[j]);
			if (line[j] && !ft_strncmp("F", &line[j], 1))
				info->floor_color = get_rgb(&line[j]);
			if (line[j] && !ft_strncmp("S", &line[j], 1))
				get_tex_path(info, &line[j], 'P');
			if (line[j] == '1' && j == 0)
			{
				tmp[i] = ft_strdup(&line[j]);
				i++;
			}
			if (line[j] == '2')
				info->sprite.nb_sprite++;
			if (line[j])
				j++;
		}
		free (line);
		line = 0;
	}
	tmp[i] = ft_strdup(line);
	free(line);
	get_map(info, tmp);
	// printf ("|%f|\n", info->res_x);
	// printf ("|%f|\n", info->res_y);
	// printf ("|%s|\n", info->north_path);
	// printf ("|%s|\n", info->south_path);
	// printf ("|%s|\n", info->weast_path);
	// printf ("|%s|\n", info->east_path);
	// printf ("|%s|\n", info->sprite_path);
	// printf ("|%d|\n", info->celling_color);
	// printf ("|%d|\n", info->floor_color);
	close (fd);
	return (0);
}