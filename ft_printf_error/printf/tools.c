/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 06:14:21 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/12 13:40:27 by mbrizion         ###   ########.fr       */
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
