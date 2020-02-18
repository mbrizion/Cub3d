/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 05:04:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/17 01:15:16 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int		charcmp(char c, char c2)
{
	if (c == c2)
		return (1);
	return (0);
}

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

size_t	strlen_spaces(const char *s)
{
	int len;
	int spaces;

	len = 0;
	spaces = 0;
	while (s[len])
	{
		if (s[len] == ' ')
			spaces++;
		len++;
	}
	return (len - spaces);
}