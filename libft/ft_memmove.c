/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 20:03:35 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/21 21:10:42 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;

	if (!dest && !src)
		return (NULL);
	if (!n || !src)
		return (dest);
	destination = (char *)dest;
	source = (char *)src;
	if (dest > src)
	{
		while (n--)
			destination[n] = source[n];
	}
	else
		ft_memcpy(destination, src, n);
	return (destination);
}
