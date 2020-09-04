/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:50:20 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/19 16:50:21 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*scur;
	unsigned char	*dcur;

	scur = (unsigned char*)src;
	dcur = (unsigned char*)dst;
	if (dst == src)
		return (dst);
	while (n-- > 0)
		dcur[n] = scur[n];
	return (dst);
}
