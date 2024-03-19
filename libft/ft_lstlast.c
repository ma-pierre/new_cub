/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 04:27:51 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/26 21:56:42 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (0);
	while (lst->next != 0)
	{
		lst = lst->next;
	}
	return (lst);
}
/*
int     main(void)
{
        t_list  *a;
        t_list  *b;

        a = ft_lstnew("test");
        b = ft_lstnew("ytest");
	b->next = a;
	b = ft_lstlast(b);
	printf("%s",((char *)b->content));
}*/
