/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 11:00:57 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/19 16:51:55 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	len;
	char			*buf;

	i = 0;
	len = 0;
	if (!s || !f)
		return (0);
	while (s[len])
		len++;
	if (!(buf = malloc((len + 1) * sizeof(char))))
		return (0);
	while (s[i])
	{
		buf[i] = (*f)(i, s[i]);
		i++;
	}
	buf[i] = '\0';
	return (buf);
}
