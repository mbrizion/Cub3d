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
		ft_printf_error("Error\nMissing map\n");
}

void		error(int error_id)
{
	if (error_id > 0)
		if (error_id == 80)
			ft_printf_error("Error\nTexture not found (Sprite)\n");
		else
			ft_printf_error("Error\nTexture not found (%c)\n", (char)error_id);
	else if (error_id == -1)
		ft_printf_error("Error\nMultiple spawnpoint\n");
	else if (error_id == -2)
		ft_printf_error("Error\nNo spawnpoint\n");
	else if (error_id == -3)
		ft_printf_error("Error\nMap error\n");
	else if (error_id == -4)
		ft_printf_error("Error\nMalloc failed\n");
	else if (error_id == -5)
		ft_printf_error("Error\nWrong texture path\n");
	else if (error_id == -6)
		ft_printf_error("Error\nBad value for floor or cieling rgb\n");
	else if (error_id == -7)
		ft_printf_error("Error\nFile name error\n");
	else if (error_id == -8)
		ft_printf_error("Error\nResolution error\n");
	else if (error_id == -9)
		ft_printf_error("Error\nRGB not found\n");
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
