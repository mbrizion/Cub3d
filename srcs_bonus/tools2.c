/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:47:30 by user42            #+#    #+#             */
/*   Updated: 2020/09/17 03:00:55 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void		error2(int error_id)
{
	if (error_id == -10)
		ft_putstr_fd("Error\nMissing map\n", ERROR);
}

void		error(int error_id)
{
	if (error_id > 0)
		if (error_id == 80)
			ft_putstr_fd("Error\nTexture not found (Sprite)\n", ERROR);
		else
			ft_putstr_fd("Error\nTexture not found\n", ERROR);
	else if (error_id == -1)
		ft_putstr_fd("Error\nMultiple spawnpoint\n", ERROR);
	else if (error_id == -2)
		ft_putstr_fd("Error\nNo spawnpoint or no map\n", ERROR);
	else if (error_id == -3)
		ft_putstr_fd("Error\nMap error\n", ERROR);
	else if (error_id == -4)
		ft_putstr_fd("Error\nMalloc failed\n", ERROR);
	else if (error_id == -5)
		ft_putstr_fd("Error\nWrong texture path\n", ERROR);
	else if (error_id == -6)
		ft_putstr_fd("Error\nBad value for floor or cieling rgb\n", ERROR);
	else if (error_id == -7)
		ft_putstr_fd("Error\nFile name error\n", ERROR);
	else if (error_id == -8)
		ft_putstr_fd("Error\nResolution error\n", ERROR);
	else if (error_id == -9)
		ft_putstr_fd("Error\nRGB not found or invalid\n", ERROR);
	error2(error_id);
	exit(-1);
}

void		sprite_tex(t_info *info, char *line, int i, int j)
{
	int k;

	k = 0;
	info->sprite.sprite_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->sprite.sprite_path, &line[i], ((j - i) + 1));
	while (info->sprite.sprite_path[k] && info->sprite.sprite_path[k] != ' '
	&& info->sprite.sprite_path[k] != '\t')
		k++;
	info->sprite.sprite_path[k] = '\0';
}

void		floor_tex(t_info *info, char *line, int i, int j)
{
	int k;

	k = 0;
	info->floor_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->floor_path, &line[i], ((j - i) + 1));
	while (info->floor_path[k] && info->floor_path[k] != ' '
	&& info->floor_path[k] != '\t')
		k++;
	info->floor_path[k] = '\0';
}

void		cieling_tex(t_info *info, char *line, int i, int j)
{
	int k;

	k = 0;
	info->cieling_path = malloc(sizeof(char) * ((j - i) + 1));
	ft_strlcpy(info->cieling_path, &line[i], ((j - i) + 1));
	while (info->cieling_path[k] && info->cieling_path[k] != ' '
	&& info->cieling_path[k] != '\t')
		k++;
	info->cieling_path[k] = '\0';
}
