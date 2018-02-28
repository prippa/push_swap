/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prippa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:38:55 by prippa            #+#    #+#             */
/*   Updated: 2017/11/08 13:39:04 by prippa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *link;
	t_list *fresh;

	if (!lst)
		return (NULL);
	if ((fresh = ft_lstnew(lst->content, lst->content_size)) == NULL)
		return (NULL);
	fresh = f(lst);
	link = fresh;
	while (lst->next)
	{
		link->next = f(lst->next);
		link = link->next;
		lst = lst->next;
	}
	return (fresh);
}
