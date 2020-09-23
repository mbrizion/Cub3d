/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:47:30 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 00:45:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error2(int error_id)
{
	if (error_id == -10)
		ft_printf_error("Error\nMissing or too many args\n");
	else if (error_id == -11)
		ft_printf_error("Error\nDouble key\n");
	else if (error_id == -12)
	{
		ft_printf_error("Error\nOverflow protection");
		ft_printf_error(", even NASA doesn't have this screen resolution\n");
	}
	else if (error_id == -13)
		ft_printf_error("Error\ninvalid option, only --save available\n");
	exit(-1);
}

void	error(int error_id)
{
	if (error_id > 0)
		if (error_id == 80)
			ft_printf_error("Error\nTexture not found (Sprite)\n");
		else
			ft_printf_error("Error\nTexture not found (%c)\n", (char)error_id);
	else if (error_id == -1)
		ft_printf_error("Error\nMultiple spawnpoint\n");
	else if (error_id == -2)
		ft_printf_error("Error\nNo spawnpoint or no map\n");
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
		ft_printf_error("Error\nRGB not found or invalid\n");
	error2(error_id);
	exit(-1);
}

void	sprite_tex(t_info *info, char *line, int j)
{
	int k;

	k = 0;
	if (info->sprite.sprite_path)
		error2(-11);
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	info->sprite.sprite_path = malloc(sizeof(char) * ft_strlen(&line[j]) + 1);
	ft_strlcpy(info->sprite.sprite_path, &line[j], ft_strlen(&line[j]) + 1);
	while (info->sprite.sprite_path[k] && info->sprite.sprite_path[k] != ' '
	&& info->sprite.sprite_path[k] != '\t')
		k++;
	info->sprite.sprite_path[k] = '\0';
}
