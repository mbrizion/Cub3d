/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:04:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/16 23:09:54 by user42           ###   ########.fr       */
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

char	*ft_strdup_len(const char *s1, int len)
{
	char	*cpy;

	if (!(cpy = malloc(len + 1 * sizeof(char))))
		return (0);
	ft_strlcpy(cpy, s1, len);
	return (cpy);
}

int		get_rgb(char *str)
{
	char	**tmp;
	int		color;
	int		i;

	i = 0;
	color = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	while (str[i++])
	{
		if (str[i] && (str[i] == ' ' || str[i] == '\t'))
			error(-6);
	}
	tmp = ft_split(str, ',');
	color += ft_atoi(tmp[0]) << 16;
	color += ft_atoi(tmp[1]) << 8;
	color += ft_atoi(tmp[2]);
	i = 0;
	while (i < 4)
		free(tmp[i++]);
	free(tmp);
	return (color);
}

int		close_window(void)
{
	exit(0);
}
