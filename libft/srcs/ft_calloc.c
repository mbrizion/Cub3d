/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:48:09 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/19 16:48:11 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_calloc(size_t count, size_t size)
{
	void *mem;

	if (!count || !size)
	{
		count = 1;
		size = 1;
	}
	mem = 0;
	if ((mem = malloc(count * size)))
		ft_bzero(mem, count * size);
	return (mem);
}
