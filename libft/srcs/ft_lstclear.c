/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:51:41 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/15 16:51:06 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*to_del;

	if (!lst || !del)
		return ;
	to_del = *lst;
	while (to_del != NULL)
	{
		*lst = (*lst)->next;
		(del)(to_del->content);
		free(to_del);
		to_del = *lst;
	}
}
