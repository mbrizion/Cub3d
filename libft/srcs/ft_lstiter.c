/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 11:15:09 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/15 16:52:20 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*to_app;

	if (!lst || !f)
		return ;
	to_app = lst;
	while (to_app != NULL)
	{
		lst = (lst)->next;
		(f)(to_app->content);
		to_app = lst;
	}
}
