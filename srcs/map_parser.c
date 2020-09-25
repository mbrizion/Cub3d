/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 03:37:38 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/24 04:55:39 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			empty_line(t_info *info)
{
	int i;

	i = 0;
	while (info->line_buf[i])
	{
		if (info->file_len < 8)
		{
			if (info->line_buf[i] && info->line_buf[i] != '\t'
			&& info->line_buf[i] != ' ')
			{
				return (copy_file(info));
			}
		}
		else
			return (copy_file(info));
		i++;
	}
	if (info->file_len > 8 && i == 0)
		return (copy_file(info));
	free(info->line_buf);
	return (0);
}

int			identify_info(char *s, int j, t_info *info)
{
	if (s[j] && !ft_strncmp("R", &s[j], 1))
		get_res(info, s);
	else if (s[j] && !ft_strncmp("NO", &s[j], 2))
		get_tex_path(info, s, 'N');
	else if (s[j] && !ft_strncmp("SO", &s[j], 2))
		get_tex_path(info, s, 'S');
	else if (s[j] && !ft_strncmp("WE", &s[j], 2))
		get_tex_path(info, s, 'W');
	else if (s[j] && !ft_strncmp("EA", &s[j], 2))
		get_tex_path(info, s, 'E');
	else if (s[j] && !ft_strncmp("S", &s[j], 1)
	&& ft_strncmp("SO", &s[j], 2))
		get_tex_path(info, s, 'P');
	else if (s[j] && !ft_strncmp("C", &s[j], 1))
		info->cieling_color = get_rgb(&s[j]);
	else if (s[j] && !ft_strncmp("F", &s[j], 1))
		info->floor_color = get_rgb(&s[j]);
	return (0);
}

void		get_info(t_info *info)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 8)
	{
		j = 0;
		while (j < (int)ft_strlen(info->file[i]))
		{
			if (info->file[i][j] && info->file[i][j] != '\t'
			&& info->file[i][j] != ' ')
				identify_info(info->file[i], j, info);
			j++;
		}
		i++;
	}
}

int			get_file_len(char *path, t_info *info, t_ptr *ptr)
{
	int		fd;
	int		ret;
	char	*buf;

	ret = 1;
	buf = 0;
	mlx_get_screen_size(ptr->mlx_ptr, &info->w, &info->h);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &buf) > 0))
	{
		info->file_len++;
		free(buf);
	}
	free(buf);
	close(fd);
	return (0);
}

int			parser(t_info *info, char *path, t_ptr *ptr)
{
	int		ret;
	int		fd;
	int		i;

	info_init(info);
	get_file_len(path, info, ptr);
	if ((fd = open(path, O_RDONLY)) < 0)
		error2(-14);
	if (!(info->file = malloc(sizeof(char *) * info->file_len)))
		error(-4);
	ret = 1;
	i = 0;
	info->file_len = 0;
	while ((ret = get_next_line(fd, &info->line_buf) > 0))
		empty_line(info);
	info->file[info->file_index] = ft_strdup(info->line_buf);
	free(info->line_buf);
	get_info(info);
	check_info(info);
	info->map_start = 8;
	get_map(info);
	conv_map(info);
	map_checker(info);
	close(fd);
	return (0);
}
