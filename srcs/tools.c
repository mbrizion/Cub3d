/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:04:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/08 02:35:32 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_nbrlen(int n)
{
	int			i;
	int			len;
	long int	nb;

	i = 0;
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
	int		i;

	if (!(cpy = malloc(len + 1 * sizeof(char))))
		return (0);
	i = 0;
	ft_strlcpy(cpy, s1, len);
	return (cpy);
}

int		get_rgb(char *str)
{
	char	**tmp;
	int		color;

	color = 0;
	tmp = ft_split(str, ',');
	color += ft_atoi(tmp[0]) << 16;
	color += ft_atoi(tmp[1]) << 8;
	color += ft_atoi(tmp[2]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	return (color);
}

int		close_window(void)
{
	exit(0);
}
