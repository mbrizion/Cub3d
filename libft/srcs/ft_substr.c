/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:47:06 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/19 16:52:23 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*ret;
	unsigned int	slen;

	if (!s)
		return (0);
	slen = ft_strlen(s);
	if (start > slen)
		start = slen;
	if (start + len > slen)
		len = slen - start;
	if (!(ret = malloc((len + 1) * sizeof(char))))
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		ret[i] = s[start + i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
