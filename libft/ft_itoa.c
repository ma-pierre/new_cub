/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:30:37 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/14 18:13:48 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static unsigned int	count_malloc(int n)
{
	unsigned int	c;

	c = 0;
	if (n <= 0)
		c++;
	while (n != 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char			*str;
	char			neg;
	unsigned int	c;

	neg = '\0';
	if (n < 0)
		neg = '-';
	c = count_malloc(n);
	str = malloc((c + 1) * sizeof(char));
	if (!str)
		return (0);
	str[c] = '\0';
	while (c)
	{
		if (n < 0)
			str[--c] = -(n % 10) + '0';
		else
			str[--c] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		str[c] = neg;
	return (str);
}
