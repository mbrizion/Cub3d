/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 06:14:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/03 22:41:17 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_assign(const char *str, int index, char c)
{
	int nbs;

	nbs = 0;
	while (str[index] && str[index] != '.')
		index++;
	while (str[index] && str[index] != c)
	{
		if (ft_isdigit(str[index]))
		{
			nbs = ft_atoi(&str[index]);
			break ;
		}
		index++;
	}
	return (nbs);
}

void	ft_putstr_fd(char *s, int fd)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int		ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) ? 1 : 0;
}
