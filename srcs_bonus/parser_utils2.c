/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:10:27 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/16 05:20:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		north_tex(t_info *info, char *line, int i, int j)
{
	info->north_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->north_path, &line[i], ((j - i) + 1));
}

void		south_tex(t_info *info, char *line, int i, int j)
{
	info->south_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->south_path, &line[i], ((j - i) + 1));
}

void		east_tex(t_info *info, char *line, int i, int j)
{
	info->east_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->east_path, &line[i], ((j - i) + 1));
}

void		weast_tex(t_info *info, char *line, int i, int j)
{
	info->weast_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->weast_path, &line[i], ((j - i) + 1));
}

void		parser_loop(char *line, t_info *info, int j)
{
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
		get_tex_path(info, &line[j], 'C');
	else if (line[j] && !ft_strncmp("F", &line[j], 1))
		get_tex_path(info, &line[j], 'F');
	else if (line[j] && !ft_strncmp("S", &line[j], 1)
	&& ft_strncmp("SO", &line[j], 2))
		get_tex_path(info, &line[j], 'P');
}
