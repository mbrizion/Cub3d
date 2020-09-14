/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jacktatoume <jacktatoume@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:51:14 by mbrizion          #+#    #+#             */
/*   Updated: 2020/03/13 09:23:25 by jacktatoume      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	int		slen;

	slen = 0;
	while (s1[slen])
		++slen;
	++slen;
	if (!(cpy = malloc(slen * sizeof(char))))
		return (0);
	while (slen--)
		cpy[slen] = s1[slen];
	return (cpy);
}
