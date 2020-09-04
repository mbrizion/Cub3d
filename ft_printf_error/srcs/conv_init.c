/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:00:31 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/12 13:37:54 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_init_c(t_convert *conv)
{
	conv[0].c = 'c';
}

void		conv_init_fun(t_convert *conv)
{
	conv[0].fun = &conv_c;
	conv[1].fun = NULL;
}

t_convert	*conv_init(void)
{
	t_convert *conv;

	if (!(conv = (t_convert*)malloc(sizeof(t_convert) * 10)))
		return (NULL);
	conv_init_c(conv);
	conv_init_fun(conv);
	return (conv);
}

t_toprint	*toprint_init(void)
{
	t_toprint *toprint;

	if (!(toprint = ((t_toprint*)malloc(sizeof(t_toprint)))))
		return (NULL);
	return (toprint);
}
