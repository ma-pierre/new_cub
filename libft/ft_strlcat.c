/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:22:16 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/21 23:26:06 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	c;

	if ((!dst || !src) && !dstsize)
		return (0);
	i = ft_strlen(dst);
	j = ft_strlen(src);
	c = 0;
	if (dstsize <= i || dstsize == 0)
		return (j + dstsize);
	while (src[c] && ((i + c) < dstsize - 1))
	{
		dst[i + c] = src[c];
		c++;
	}
	dst[i + c] = '\0';
	return (i + j);
}
