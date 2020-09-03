/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 03:37:38 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/04 00:06:25 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// t_sprite_pos	*get_sprite(int x, int y, t_info *info)
// {
// 	t_sprite_pos *sprt;

// 	if (!(sprt = malloc(sizeof(t_sprite_pos))))
// 		return (0);
// 	sprt->pos_x = x + 0.5;
// 	sprt->pos_y = y + 0.5;
// 	return(sprt);
// }

int		av_char(char c)
{
	if (c == 'N' || c == 'W' || c == 'E' || c == 'S' || c == '0' || c == '1' || c == '2' || c == ' ')
		return (1);
	else if (c == '\t')
		return (0);
	return (0);
}

int		check_pos(int x, int y, t_info *info, char c)
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

char **fill_map(char **map, t_info *info)
{
	int i;
	int j;
	char **tmp;
	if (!(tmp = malloc(sizeof(char *) * (info->map_len + 1))))
		return (0);
	i = 0;
	while (i < info->map_len)
	{
		j = 0;
		if (!(tmp[i] = malloc(sizeof(char) * info->len_line + 1)))
			return (0);
		ft_bzero(tmp[i], info->len_line + 1);
		ft_strlcpy(tmp[i], map[i], info->len_line + 1);
		while (map[i][j])
			j++;
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

int	get_map(t_info *info, char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	// if (!(info->sprite_list = malloc(sizeof(t_sprite_pos))))
	// 	return (-1);
	// info->sprite_list->next = 0;
	info->map = malloc(sizeof(int *) * (info->map_len + 1));
	while (i < info->map_len + 1)
	{
		if (!(info->map[i] = malloc(sizeof(int) * ft_strlen(map[i]))))
			return (-1);
		while (j < ft_strlen(map[i]))
		{
			if (!av_char(map[i][j]))
				error (-8);
			if (map[i][j] == '2')
			{
				info->sprite_pos.pos_x = i + 0.5;
				info->sprite_pos.pos_y = j + 0.5;
				// if (!(info->sprite_list->next = malloc(sizeof(t_sprite_pos))))
				// 	return (-1);
				// info->sprite_list->content = get_sprite(i, j, info);
				// info->sprite_list = info->sprite_list->next;
				// info->sprite_list->next = 0;
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
		info->sprite.sprite_path = malloc(sizeof(char) * ((j - i) + 1));
		ft_strlcpy(info->sprite.sprite_path, &line[i], ((j - i) + 1));
	}
	
}

int check_info(char *s)
{
	int j;
	int len;

	j = 0;
	len = ft_strlen(s);
	while (j < len + 1)
	{
		while (j < len + 1 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\v' || s[j] == '\f' || s[j] == '\r'))
				j++;
		if (s[j] && !ft_strncmp("R", &s[j], 1))
			return(1);
		else if (s[j] && !ft_strncmp("NO", &s[j], 2))
			return(1);
		else if (s[j] && !ft_strncmp("SO", &s[j], 2))
			return(1);
		else if (s[j] && !ft_strncmp("WE", &s[j], 2))
			return(1);
		else if (s[j] && !ft_strncmp("EA", &s[j], 2))
			return(1);
		else if (s[j] && !ft_strncmp("C", &s[j], 1))
			return(1);
		else if (s[j] && !ft_strncmp("F", &s[j], 1))
			return(1);
		else if (s[j] && !ft_strncmp("S", &s[j], 1) && ft_strncmp("SO", &s[j], 2))
			return(1);
		j++;
	}
	return (0);
}

void info_init(t_info *info)
{
	info->map_len = 1;
	info->file_len = 1;
	info->len_line = 0;
	info->spawn_dir = '\0';
	info->res_x = 0;
	info->res_y = 0;
	info->pos_x = 0;
	info->pos_y = 0;
	info->north_path = 0;
	info->south_path = 0;
	info->east_path = 0;
	info->weast_path = 0;
	info->floor_rgb = 0;
	info->cieling_rgb = 0;
}

int	parser(t_info *info, char *path)
{
	char *line;
	int j;
	int ret;
	int fd;
	int i;
	char **tmp;

	info_init(info);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &line) > 0))
		info->file_len++;
	close (fd);
	if (!(tmp = malloc(sizeof(char *) * info->file_len)))
		return (-1);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	line = 0;
	ret = 1;
	i = 0;
	while ((ret = get_next_line(fd, &line) > 0))
	{
		j = 0;
		while (line[j])
		{
			if (check_info(line))
			{
				while (line[j] && (line[j] == ' ' || line[j] == '\t'))
					j++;
				if (line[j] && !ft_strncmp("R", &line[j], 1))
					get_res(info, &line[j]);
				else if (line[j] && !ft_strncmp("NO", &line[j], 2))
					get_tex_path(info, &line[j], 'N');
				else if (line[j] && !ft_strncmp("SO", &line[j], 2))
					get_tex_path(info, &line[j], 'S');
				else if (line[j] && !ft_strncmp("WE", &line[j], 2))
					get_tex_path(info, &line[j], 'W');
				else if (line[j] && !ft_strncmp("EA", &line[j], 2))
					get_tex_path(info, &line[j], 'E');
				else if (line[j] && !ft_strncmp("C", &line[j], 1))
					info->cieling_color = get_rgb(&line[j]);
				else if (line[j] && !ft_strncmp("F", &line[j], 1))
					info->floor_color = get_rgb(&line[j]);
				else if (line[j] && !ft_strncmp("S", &line[j], 1) && ft_strncmp("SO", &line[j], 2))
					get_tex_path(info, &line[j], 'P');
			}
			else if (!check_info(line) && line[j] != '\n')
			{
				tmp[i] = ft_strdup(&line[j]);
				info->len_line = info->len_line < ft_strlen(line) ? ft_strlen(line) : info->len_line;
				i++;
				break ;
			}
			if (line[j])
				j++;
		}
		free (line);
		line = 0;
	}
	tmp[i] = ft_strdup(&line[j]);
	free(line);
	info->map_len = i;
	tmp = fill_map(tmp, info);
	get_map(info, tmp);
	map_checker(tmp, info);
	while (i)
		free(tmp[i--]);
	free(tmp);

	close (fd);
	return (0);
}