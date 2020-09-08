/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrizion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:57:15 by mbrizion          #+#    #+#             */
/*   Updated: 2019/11/15 16:56:01 by mbrizion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *ls;
	t_list *new;

	ls = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&ls, del);
			return (ls);
		}
		ft_lstadd_back(&ls, new);
		lst = lst->next;
	}
	return (ls);
}
