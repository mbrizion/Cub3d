/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <mbrizion@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:27:19 by mbrizion          #+#    #+#             */
/*   Updated: 2020/02/12 13:41:26 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../../libft/libft.h"

typedef struct	s_toprint
{

	char		*toprint;
	int			len;
	char		c;
	int			index;
	int			neg;
	int			nbr_len;
	int			b_prec;
	int			i;
	int			j;

}				t_toprint;

typedef t_toprint* (*t_fun)(const char *str, va_list ap, t_toprint *toprint);

typedef struct	s_convert
{
	char		c;
	t_fun		fun;
}				t_convert;

typedef struct	s_flags
{
	int			padding;
	int			zero;
	int			precision;
	int			align;
	int			nul_prec;
	char		c;
	int			b_nbs;
}				t_flags;

int				ft_printf_error(const char *str, ...);
t_convert		*conv_init(void);
t_toprint		*toprint_init(void);
t_flags			*flags_init(const char *str, char spec, int index, va_list ap);
t_toprint		*conv_c(const char *str, va_list ap, t_toprint *toprint);
int				conv_locator(const char *str,
				t_convert *conv, va_list ap, t_toprint *toprint);
int				prec_assign(const char *str, int index, char c);

#endif
