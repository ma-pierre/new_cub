/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 04:53:38 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/26 21:47:19 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*a;

	if (!new)
		return ;
	if (*lst)
	{
		a = *lst;
		while (a->next != 0)
		{
			a = a->next;
		}
		a->next = new;
	}
	else
		*lst = new;
}
/*
int     main(void)
{
        t_list  *a;
        t_list  *b;
	t_list	*c;

        a = ft_lstnew("test");
        b = ft_lstnew("ytest");
	c = ft_lstnew("cccc");
        a->next = b;
	ft_lstadd_back(&a, c);
        while (a != NULL)
        {
                printf("%s", ((char *)a->content));
                a = a->next;
        }
}*/
