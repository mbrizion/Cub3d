/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 05:47:30 by user42            #+#    #+#             */
/*   Updated: 2020/09/24 04:54:53 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error2(int error_id)
{
	if (error_id == -10)
		ft_putstr_fd("Error\nMissing or too many args\n", ERROR);
	else if (error_id == -11)
		ft_putstr_fd("Error\nDouble key\n", ERROR);
	else if (error_id == -12)
	{
		ft_putstr_fd("Error\nOverflow protection", ERROR);
		ft_putstr_fd(", even NASA doesn't have ", ERROR);
		ft_putstr_fd("this screen resolution\n", ERROR);
	}
	else if (error_id == -13)
		ft_putstr_fd("Error\ninvalid option, only --save available\n", ERROR);
	else if (error_id == -14)
		ft_putstr_fd("Error\nFile not found\n", ERROR);
	exit(-1);
}

void	error(int error_id)
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

void	sprite_tex(t_info *info, char *line, int j)
{
	int k;

	k = 0;
	if (info->sprite.sprite_path)
		error2(-11);
	if (line[j] && line[j] != ' ')
		error(-5);
	while (line[j] && (line[j] == ' ' || line[j] == '\t'))
		j++;
	info->sprite.sprite_path = malloc(sizeof(char) * ft_strlen(&line[j]) + 1);
	ft_strlcpy(info->sprite.sprite_path, &line[j], ft_strlen(&line[j]) + 1);
	while (info->sprite.sprite_path[k] && info->sprite.sprite_path[k] != ' '
	&& info->sprite.sprite_path[k] != '\t')
		k++;
	info->sprite.sprite_path[k] = '\0';
}

int		copy_file(t_info *info)
{
	info->file[info->file_index] = ft_strdup(info->line_buf);
	info->file_index++;
	info->file_len++;
	free(info->line_buf);
	return (1);
}
