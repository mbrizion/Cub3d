/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 04:41:24 by user42            #+#    #+#             */
/*   Updated: 2020/09/16 05:07:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void		error_check(t_info *info)
{
	if (!info->res_x || !info->res_y)
		error(-8);
	if (!info->floor_color || !info->cieling_color)
		error(-9);
}
