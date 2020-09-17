/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:24:01 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/04 04:10:39 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

char		conv_identifier(const char *str, int index)
{
	while (str[index] && !ft_isalpha(str[index]))
	{
		if (str[index] == '%')
			return ('%');
		index++;
	}
	return (str[index]);
}

int			do_conv(const char *str, t_convert *conv,
			va_list ap, t_toprint *toprint)
{
	toprint->c = str[toprint->i];
	conv[toprint->j].fun(str, ap, toprint);
	return (0);
}

int			conv_locator(const char *str, t_convert *conv,
			va_list ap, t_toprint *toprint)
{
	char	c;

	toprint->i = 0;
	toprint->j = 0;
	while (str[toprint->i])
	{
		while (str[toprint->i] && str[toprint->i] != '%'
		&& conv[toprint->j].fun)
		{
			toprint->i += write(2, &str[toprint->i], 1);
			toprint->len++;
		}
		if (str[toprint->i] && str[toprint->i + 1])
			c = conv_identifier(str, toprint->i + 1);
		c == '%' ? toprint->i++ : toprint->i;
		toprint->index = toprint->i;
		while (str[toprint->i] && str[toprint->i] != c)
			toprint->i++;
		while (conv[toprint->j].fun && str[toprint->i] != conv[toprint->j].c)
			toprint->j++;
		if (str[toprint->i] && str[toprint->i] == conv[toprint->j].c)
			toprint->j = do_conv(str, conv, ap, toprint);
		str[toprint->i] ? ++toprint->i : toprint->i;
	}
	return (toprint->len);
}

int			ft_printf_error(const char *str, ...)
{
	t_convert	*conv;
	t_toprint	*toprint;
	va_list		ap;

	va_start(ap, str);
	if (!(ft_strchr(str, '%')))
	{
		ft_putstr_fd((char*)str, 1);
		return ((int)ft_strlen(str));
	}
	if (!(toprint = toprint_init()))
		return (-1);
	if (!(conv = conv_init()))
	{
		free(toprint);
		return (-1);
	}
	toprint->c = '\0';
	toprint->len = 0;
	conv_locator(str, conv, ap, toprint);
	va_end(ap);
	free(toprint);
	free(conv);
	return (-1);
}
