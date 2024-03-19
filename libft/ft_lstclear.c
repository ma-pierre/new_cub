/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 05:50:20 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/26 22:58:23 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (del)(void *))
{
	t_list	*dup;
	t_list	*temp;

	if (!lst || !del)
		return ;
	dup = *lst;
	while (dup)
	{
		temp = dup;
		dup = temp->next;
		del(temp->content);
		free(temp);
	}
	*lst = 0;
}	
