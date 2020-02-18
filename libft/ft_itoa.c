/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:41:44 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/19 16:49:13 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(int n)
{
	int			i;
	int			len;
	long int	nb;

	i = 0;
	len = 0;
	nb = n;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*ft_rev(char *array)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	j = 0;
	while (array[j])
		j++;
	j--;
	while (i < j - i)
	{
		tmp = array[j - i];
		array[j - i] = array[i];
		array[i] = tmp;
		i++;
	}
	return (array);
}

char	*ft_itoa(int n)
{
	char		*array;
	int			len;
	int			i;
	long int	nb;

	nb = n;
	len = ft_nbrlen(n);
	i = 0;
	if (!(array = malloc((len + 1) * sizeof(char))))
		return (0);
	if (nb == 0)
		array[i++] = 0 + '0';
	if (nb < 0)
		nb *= -1;
	while (nb > 0)
	{
		array[i++] = nb % 10 + '0';
		nb /= 10;
	}
	if (n < 0)
		array[i] = '-';
	array[len] = '\0';
	return (ft_rev(array));
}
