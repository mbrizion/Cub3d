/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 03:37:38 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/08 02:06:48 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		get_tex_path(t_info *info, char *line, char dir)
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
		while (j < len + 1 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\v'
		|| s[j] == '\f' || s[j] == '\r'))
			j++;
		if (identify_info(s, j))
			return (1);
		j++;
	}
	return (0);
}

void		info_init(t_info *info)
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

int			parser(t_info *info, char *path)
{
	char	*line;
	int		j;
	int		ret;
	int		fd;
	int		i;
	char	**tmp;

	info_init(info);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &line) > 0))
		info->file_len++;
	close(fd);
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
			if (check_info(line) && !info->sprite.sprite_path)
			{
				while (line[j] && (line[j] == ' ' || line[j] == '\t'))
					j++;
				parser_loop(line, info, j);
			}
			else if (line[j] != '\n')
			{
				tmp[i] = ft_strdup(&line[j]);
				info->len_line = info->len_line < (int)ft_strlen(line)
				? ft_strlen(line) : info->len_line;
				i++;
				break ;
			}
			if (line[j])
				j++;
		}
		free(line);
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
	close(fd);
	if (!info->spawn_dir)
		error(-2);
	return (0);
}
