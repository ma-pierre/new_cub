/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 01:08:57 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/23 04:23:52 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
int     main(void)
{
        t_list  *a;
        t_list  *b;
	
        a = ft_lstnew("test");
        b = ft_lstnew("ytest");
	ft_lstadd_front(&a, b);
        printf("%d", (ft_lstsize(b)));
}*/
