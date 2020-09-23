/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 02:10:27 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/23 02:52:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		north_tex(t_info *info, char *line, int j)
{
	int k;

	k = 0;
	if (info->north_path)
		error2(-11);
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	info->north_path = malloc(sizeof(char) * ft_strlen(&line[j]) + 1);
	ft_strlcpy(info->north_path, &line[j], ft_strlen(&line[j]) + 1);
	while (info->north_path[k] && info->north_path[k] != ' '
	&& info->north_path[k] != '\t')
		k++;
	info->north_path[k] = '\0';
}

void		south_tex(t_info *info, char *line, int j)
{
	int k;

	k = 0;
	if (info->south_path)
		error2(-11);
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	info->south_path = malloc(sizeof(char) * ft_strlen(&line[j]) + 1);
	ft_strlcpy(info->south_path, &line[j], ft_strlen(&line[j]) + 1);
	while (info->south_path[k] && info->south_path[k] != ' '
	&& info->south_path[k] != '\t')
		k++;
	info->south_path[k] = '\0';
}

void		east_tex(t_info *info, char *line, int j)
{
	int k;

	k = 0;
	if (info->east_path)
		error2(-11);
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	info->east_path = malloc(sizeof(char) * ft_strlen(&line[j]) + 1);
	ft_strlcpy(info->east_path, &line[j], ft_strlen(&line[j]) + 1);
	while (info->east_path[k] && info->east_path[k] != ' '
	&& info->east_path[k] != '\t')
		k++;
	info->east_path[k] = '\0';
}

void		weast_tex(t_info *info, char *line, int j)
{
	int k;

	k = 0;
	if (info->weast_path)
		error2(-11);
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	info->weast_path = malloc(sizeof(char) * ft_strlen(&line[j]) + 1);
	ft_strlcpy(info->weast_path, &line[j], ft_strlen(&line[j]) + 1);
	while (info->weast_path[k] && info->weast_path[k] != ' '
	&& info->weast_path[k] != '\t')
		k++;
	info->weast_path[k] = '\0';
}
