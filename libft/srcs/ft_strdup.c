/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:51:14 by mbrizion          #+#    #+#             */
/*   Updated: 2020/09/16 03:22:12 by user42           ###   ########.fr       */
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
	ft_bzero(cpy, slen);
	while (slen--)
		cpy[slen] = s1[slen];
	return (cpy);
}
