/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:04:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/16 05:16:03 by user42           ###   ########.fr       */
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
	exit(-1);
}

int		close_window(void)
{
	exit(0);
}
