/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:04:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/17 02:55:20 by user42           ###   ########.fr       */
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
		i += 1;
	if (s[1])
		i += 1;
	if (s[2])
		i += 1;
	if (i != 3)
		return (0);
	return (1);
}

void	free_rgb(char **tmp, char *buf)
{
	int i;
	int a;

	i = 0;
	a = check_tmp(tmp);
	while (i < 3)
		free(tmp[i++]);
	free(tmp);
	free(buf);
	if (!a)
		error(-9);
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
	if (!(check_tmp(tmp)))
		free_rgb(tmp, buf);
	color += ft_atoi(tmp[0]) << 16;
	color += ft_atoi(tmp[1]) << 8;
	color += ft_atoi(tmp[2]);
	free_rgb(tmp, buf);
	return (color);
}

int		close_window(void)
{
	exit(0);
}
