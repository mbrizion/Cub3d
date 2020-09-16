/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:10:27 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/17 01:33:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		north_tex(t_info *info, char *line, int i, int j)
{
	int k;

	k = 0;
	info->north_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->north_path, &line[i], ((j - i) + 1));
	while (info->north_path[k] && info->north_path[k] != ' '
	&& info->north_path[k] != '\t')
		k++;
	info->north_path[k] = '\0';
}

void		south_tex(t_info *info, char *line, int i, int j)
{
	int k;

	k = 0;
	info->south_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->south_path, &line[i], ((j - i) + 1));
	while (info->south_path[k] && info->south_path[k] != ' '
	&& info->south_path[k] != '\t')
		k++;
	info->south_path[k] = '\0';
}

void		east_tex(t_info *info, char *line, int i, int j)
{
	int k;

	k = 0;
	info->east_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->east_path, &line[i], ((j - i) + 1));
	while (info->east_path[k] && info->east_path[k] != ' '
	&& info->east_path[k] != '\t')
		k++;
	info->east_path[k] = '\0';
}

void		weast_tex(t_info *info, char *line, int i, int j)
{
	int k;

	k = 0;
	info->weast_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->weast_path, &line[i], ((j - i) + 1));
	while (info->weast_path[k] && info->weast_path[k] != ' '
	&& info->weast_path[k] != '\t')
		k++;
	info->weast_path[k] = '\0';
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
