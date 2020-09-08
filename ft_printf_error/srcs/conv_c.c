/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 22:57:51 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/12 13:30:12 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			do_flag_c(va_list ap, t_flags *flags, int nbs)
{
	char	buf;
	int		len;

	len = 0;
	if (flags->padding || flags->align)
	{
		if (flags->align)
		{
			buf = va_arg(ap, int);
			write(2, &buf, 1);
			while (len < nbs - 1)
				len += write(2, " ", 1);
			len++;
		}
		else
		{
			while (len < nbs - 1)
				len += write(2, " ", 1);
			buf = va_arg(ap, int);
			len += write(2, &buf, 1);
		}
	}
	return (len);
}

int			do_conv_c(va_list ap, t_flags *flags)
{
	int ret;
	int len;
	int nbs;

	len = 0;
	nbs = 0;
	ret = (flags->padding || flags->align || flags->precision
		|| flags->zero) ? 1 : 0;
	if (!ret)
	{
		ret = va_arg(ap, int);
		len += write(2, &ret, 1);
	}
	if (flags->padding)
		nbs = flags->padding;
	if (nbs < 0)
	{
		flags->align = 1;
		nbs *= -1;
	}
	if (ret)
		len += do_flag_c(ap, flags, nbs);
	return (len);
}

t_toprint	*conv_c(const char *str, va_list ap, t_toprint *toprint)
{
	int		i;
	t_flags *flags;
	char	c;

	c = toprint->c;
	i = toprint->index;
	if (str[i] && str[i] == '%')
	{
		flags = flags_init(str, c, i, ap);
		toprint->len += do_conv_c(ap, flags);
		free(flags);
	}
	toprint->index = i;
	return (toprint);
}
