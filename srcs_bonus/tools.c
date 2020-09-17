/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:04:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/17 03:38:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int		ft_nbrlen(int n)
{
	int			len;
	long int	nb;

	len = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

void	floor_cieling_calcul(t_ray *ray, int y, t_game *game)
{
	if (ray->draw_end < 0)
		ray->draw_end = game->info.res_y;
	y = ray->draw_end;
	if (ray->side == 0)
	{
		game->ray_fc.floor_xwall = ray->map_x;
		game->ray_fc.floor_ywall = ray->map_y + game->tex.wall_x;
	}
	else if (ray->side == 1)
	{
		game->ray_fc.floor_xwall = ray->map_x + 1.0;
		game->ray_fc.floor_ywall = ray->map_y + game->tex.wall_x;
	}
	else if (ray->side == 2)
	{
		game->ray_fc.floor_xwall = ray->map_x + game->tex.wall_x;
		game->ray_fc.floor_ywall = ray->map_y;
	}
	else
	{
		game->ray_fc.floor_xwall = ray->map_x + game->tex.wall_x;
		game->ray_fc.floor_ywall = ray->map_y + 1.0;
	}
}

void	free_rgb(char **tmp, char *buf)
{
	int i;

	i = 0;
	while (i < 3)
		free(tmp[i++]);
	free(tmp);
	free(buf);
}

int		get_rgb(char *str)
{
	char	**tmp;
	int		color;
	int		i;
	char	*buf;
	int		j;

	color = 0;
	i = 1;
	j = 0;
	if (!(buf = malloc(sizeof(char) * ft_strlen(str))))
		return (-1);
	while (str[i++])
		if (str[i] && str[i] != ' ' && str[i] != '\t')
			buf[j++] = str[i];
	buf[j] = '\0';
	tmp = ft_split(buf, ',');
	color += ft_atoi(tmp[0]) << 16;
	color += ft_atoi(tmp[1]) << 8;
	color += ft_atoi(tmp[2]);
	free_rgb(tmp, buf);
	return (color);
}
