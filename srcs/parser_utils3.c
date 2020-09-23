/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 04:07:50 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 01:54:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int			add_sprite(int i, int j, t_info *info)
{
	t_sprite_pos *sprite_pos;

	if ((sprite_pos = malloc(sizeof(t_sprite_pos))) == 0)
		return (-1);
	sprite_pos->pos_x = i + 0.5;
	sprite_pos->pos_y = j + 0.5;
	ft_lstadd_back(&info->sprite_lst, ft_lstnew(sprite_pos));
	return (0);
}

void		assign_res(char **tmp, t_info *info)
{
	if (ft_strlen(tmp[0]) > 6)
		error2(-12);
	if (ft_strlen(tmp[1]) > 6)
		error2(-12);
	info->res_x = ft_atoi(tmp[0]);
	info->res_y = ft_atoi(tmp[1]);
	info->res_x = info->res_x > info->w ? info->w : info->res_x;
	info->res_y = info->res_y > info->h ? info->h : info->res_y;
	free(tmp[0]);
	free(tmp[1]);
	free(tmp);
}

void		get_res(t_info *info, char *line)
{
	int		i;
	char	**tmp;

	i = 1;
	if (info->res_x || info->res_y)
		error2(-11);
	while (line[i] && (line[i] == ' ' || line[i] == '\t' || line[i] == 'R'))
		i++;
	tmp = ft_split(&line[i], ' ');
	assign_res(tmp, info);
	if (info->res_x < 0)
		error(-8);
	else if (info->res_x > 0 && info->res_x < 100)
		info->res_x = 400;
	if (info->res_y < 0)
		error(-8);
	else if (info->res_y > 0 && info->res_y < 100)
		info->res_y = 200;
}

int			is_spawn(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int			conv_map(t_info *info)
{
	int		i;
	int		j;
	int		k;

	i = info->map_start;
	k = 0;
	while (i < info->file_len - info->map_start)
	{
		j = -1;
		while (++j < (int)ft_strlen(info->file[i]))
		{
			if (info->file[i][j] != ' ' && !is_spawn(info->file[i][j]))
				info->map[k][j] = info->file[i][j] - '0';
			else if (info->file[i][j] == ' ')
				info->map[k][j] = ' ';
			else if (is_spawn(info->file[i][j]))
				info->map[k][j] = 0;
		}
		i++;
		k++;
	}
	return (0);
}
