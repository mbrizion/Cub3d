/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 10:39:08 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/15 16:49:59 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	t_list *to_del;

	if (!lst || !del)
		return ;
	to_del = lst;
	lst = lst->next;
	(del)(to_del->content);
	free(to_del);
}
