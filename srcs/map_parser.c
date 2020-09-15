/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 03:37:38 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/15 05:57:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_tex_path(t_info *info, char *line, char dir)
{
	int i;
	int j;

	i = 2;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	j = i;
	while (line[j] && line[j] != ' ')
		j++;
	if (dir == 'N')
		north_tex(info, line, i, j);
	if (dir == 'S')
		south_tex(info, line, i, j);
	else if (dir == 'W')
		weast_tex(info, line, i, j);
	else if (dir == 'E')
		east_tex(info, line, i, j);
	else if (dir == 'P' && !info->sprite.sprite_path)
	{
		info->sprite.sprite_path = malloc(sizeof(char) * ((j - i) + 1));
		ft_strlcpy(info->sprite.sprite_path, &line[i], ((j - i) + 1));
	}
}

int			identify_info(char *s, int j)
{
	if (s[j] && !ft_strncmp("R", &s[j], 1))
		return (1);
	else if (s[j] && !ft_strncmp("NO", &s[j], 2))
		return (1);
	else if (s[j] && !ft_strncmp("SO", &s[j], 2))
		return (1);
	else if (s[j] && !ft_strncmp("WE", &s[j], 2))
		return (1);
	else if (s[j] && !ft_strncmp("EA", &s[j], 2))
		return (1);
	else if (s[j] && !ft_strncmp("C", &s[j], 1))
		return (1);
	else if (s[j] && !ft_strncmp("F", &s[j], 1))
		return (1);
	else if (s[j] && !ft_strncmp("S", &s[j], 1)
	&& ft_strncmp("SO", &s[j], 2))
		return (1);
	return (0);
}

int			check_info(char *s)
{
	int j;
	int len;

	j = 0;
	len = ft_strlen(s);
	while (j < len + 1)
	{
		while (j < len + 1 && (s[j] == ' ' || s[j] == '\t'))
			j++;
		if (identify_info(s, j))
			return (1);
		j++;
	}
	return (0);
}

void		info_init(t_info *info)
{
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
	info->sprite.sprite_path = 0;
	info->sprite_lst = 0;
	info->floor_color = 0;
	info->cieling_color = 0;
}

int			all_info_init(t_info *info)
{
	if (info->res_x && info->res_y && info->north_path
	&& info->south_path && info->east_path
	&& info->weast_path && info->floor_color
	&& info->cieling_color && info->sprite.sprite_path)
		return (1);
	return (0);
}

int			get_file_len(char *path, t_info *info)
{
	int fd;
	int ret;

	ret = 1;
	info->line_buf = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &info->line_buf) > 0))
	{
		info->file_len++;
		free(info->line_buf);
	}
	free(info->line_buf);
	close(fd);
	return (0);
}

int			empty_line(t_info *info)
{
	int i;

	i = 0;
	while (info->line_buf[i++])
		if (info->line_buf[i] && info->line_buf[i] != '\t' && info->line_buf[i] != ' ')
		{
			info->file[info->file_index++] = ft_strdup(info->line_buf);
			return (1);
		}
	info->count++;
	return (0);
}

int			parser(t_info *info, char *path)
{
	int		j;
	int		ret;
	int		fd;
	int		i;
	info_init(info);
	get_file_len(path, info);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	if (!(info->file = malloc(sizeof(char *) * info->file_len)))
		error(-4);
	info->line_buf = 0;
	info->file_index = 0;
	info->count = 0;
	ret = 1;
	i = 0;
	info->buf = 1;
	while ((ret = get_next_line(fd, &info->line_buf) > 0))
	{
		j = 0;
		empty_line(info);
		while (info->line_buf[j] && !all_info_init(info))
		{
			if (check_info(info->line_buf) && !info->sprite.sprite_path)
			{
				while (info->line_buf[j] &&
				(info->line_buf[j] == ' ' || info->line_buf[j] == '\t'))
					j++;
				parser_loop(info->line_buf, info, j);
			}
			else if (info->line_buf[j] != '\n')
			{
				info->len_line = info->len_line < (int)ft_strlen(info->line_buf)
				? (int)ft_strlen(info->line_buf) : info->len_line;
				break ;
			}
			if (info->line_buf[j])
				j++;
		}
		if (all_info_init(info) && info->buf)
		{
			info->buf = 0;
			info->map_start = i - info->count + 1;
		}
		free(info->line_buf);
		i++;
	}
	info->file[info->file_index] = ft_strdup(info->line_buf);
	free(info->line_buf);
	get_map(info);
	// map_checker(info->map, info);
	close(fd);
	return (0);
}
