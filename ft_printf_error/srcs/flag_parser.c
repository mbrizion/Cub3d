/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 06:13:51 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/12 13:18:12 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags			*flag_parser_2(const char *str, int i,
				t_flags *flags, va_list ap)
{
	if (ft_isdigit(str[i]) && ((!ft_isdigit(str[i - 1])
	|| (str[i - 1]) == '0')))
		flags->padding = ft_atoi(&str[i]);
	if (str[i - 1] == '0' && !ft_isdigit(str[i - 2])
	&& ft_isdigit(str[i]))
		flags->padding = ft_atoi(&str[i]);
	if (str[i] == '*' && str[i - 1] != '.')
		flags->padding = va_arg(ap, int);
	return (flags);
}

t_flags			*flag_parser(const char *str, int i, t_flags *flags, va_list ap)
{
	while (str[i] && str[i] != flags->c)
	{
		if (str[i] == '-')
			flags->align = 1;
		if (str[i] == '0' && !ft_isdigit(str[i - 1]) && str[i - 1] != '.')
			flags->zero = 1;
		if (str[i] == '.')
		{
			if (ft_isdigit(str[i + 1]) && str[i + 1] != '0')
				flags->precision = prec_assign(str, i, flags->c);
			if (str[i + 1] == '*')
				flags->precision = va_arg(ap, int);
			if (flags->precision == 0)
				flags->nul_prec = 1;
		}
		if (((str[i] == '*' || (ft_isdigit(str[i]) && !flags->precision))
		&& str[i] != '0') && str[i - 1] != '.')
			flags = flag_parser_2(str, i, flags, ap);
		i++;
	}
	return (flags);
}

t_flags			*flag_finder(const char *str, char c, int i, va_list ap)
{
	t_flags *flags;

	if (!(flags = (t_flags*)malloc(sizeof(t_flags))))
		return (NULL);
	while (str[i] && str[i] != '%')
		i++;
	flags->c = c;
	flags->align = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->padding = 0;
	flags->nul_prec = 0;
	return (flag_parser(str, i, flags, ap));
}

t_flags			*flags_init(const char *str, char c, int i, va_list ap)
{
	t_flags *flags;

	flags = flag_finder(str, c, i, ap);
	if (flags->padding < 0)
	{
		flags->padding *= -1;
		flags->align = 1;
	}
	return (flags);
}
