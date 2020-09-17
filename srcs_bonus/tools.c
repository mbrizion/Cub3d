/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:04:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/17 02:54:35 by user42           ###   ########.fr       */
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
	i = 0;
	while (i < 4)
		free(tmp[i++]);
	free(tmp);
	free(buf);
	return (color);
}

int		close_window(void)
{
	exit(0);
}
