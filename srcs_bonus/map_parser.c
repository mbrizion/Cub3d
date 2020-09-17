/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 03:37:38 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/17 02:44:02 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int			empty_line(t_info *info)
{
	int i;

	i = 0;
	while (info->line_buf[i++])
		if (info->line_buf[i] && info->line_buf[i] != '\t'
		&& info->line_buf[i] != ' ')
		{
			info->file[info->file_index++] = ft_strdup(info->line_buf);
			return (1);
		}
	info->count++;
	return (0);
}

void		inner_loop(t_info *info)
{
	int j;

	j = 0;
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
}

void		parser_info_init(t_info *info)
{
	info->line_buf = 0;
	info->file_index = 0;
	info->count = 0;
	info->buf = 1;
}

void		gnl_loop(t_info *info, int i)
{
	empty_line(info);
	inner_loop(info);
	if (all_info_init(info) && info->buf)
	{
		info->buf = 0;
		info->map_start = i - info->count + 1;
	}
	free(info->line_buf);
}

int			parser(t_info *info, char *path)
{
	int		ret;
	int		fd;
	int		i;

	info_init(info);
	get_file_len(path, info);
	if ((fd = open(path, O_RDONLY)) < 0)
		return (-1);
	if (!(info->file = malloc(sizeof(char *) * info->file_len)))
		error(-4);
	parser_info_init(info);
	ret = 1;
	i = 0;
	while ((ret = get_next_line(fd, &info->line_buf) > 0))
		gnl_loop(info, i++);
	info->file[info->file_index] = ft_strdup(info->line_buf);
	free(info->line_buf);
	check_path(info);
	error_check(info);
	get_map(info);
	conv_map(info);
	map_checker(info);
	close(fd);
	return (0);
}
