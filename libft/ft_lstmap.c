/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 20:01:00 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/26 22:52:43 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *))
{
	t_list	*dup;
	t_list	*dupfirst;

	if (!lst || !f)
		return (0);
	dup = ft_lstnew(f(lst->content));
	if (!dup)
		return (0);
	dupfirst = dup;
	while (lst->next)
	{
		lst = lst->next;
		dup->next = ft_lstnew(f(lst->content));
		if (dup->next == NULL)
		{
			ft_lstclear(&dupfirst, del);
			return (0);
		}
		dup = dup->next;
	}
	return (dupfirst);
}
