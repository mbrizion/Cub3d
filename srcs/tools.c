/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:04:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/24 02:55:38 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

int		check_tmp(char **s)
{
	int i;

	i = 0;
	if (s[0])
	{
		i += 1;
		if (s[1])
		{
			i += 1;
			if (s[2])
				i += 1;
		}
	}
	if (i != 3)
		return (0);
	return (1);
}

void	free_rgb(char **tmp)
{
	int i;

	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	error(-9);
}

int		get_color(char **tmp)
{
	int color;
	int j;

	color = 0;
	j = 0;
	color = ft_atoi(tmp[0]);
	free(tmp[0]);
	if (color < 0 || color > 255)
		error(-9);
	color = color << 16;
	j = ft_atoi(tmp[1]);
	free(tmp[1]);
	if (j < 0 || j > 255)
		error(-9);
	color += j << 8;
	j = ft_atoi(tmp[2]);
	free(tmp[2]);
	if (j < 0 || j > 255)
		error(-9);
	color += j;
	return (color);
}

int		get_rgb(char *str)
{
	char	**tmp;
	char	**buf;
	int		i;
	int		j;

	j = 0;
	buf = ft_split(str, ' ');
	while (buf[j])
		j++;
	if (j != 2)
	{
		free_buf(buf);
		error(-9);
	}
	tmp = ft_split(buf[1], ',');
	i = -1;
	while (tmp[++i])
		for_the_norm(tmp, i);
	if (!(check_tmp(tmp)))
		free_rgb(tmp);
	j = get_color(tmp);
	free_buf(buf);
	free(tmp);
	return (j);
}
