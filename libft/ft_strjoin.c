/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:22:03 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/18 02:37:06 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		j;
	char		*snew;

	snew = malloc(((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!snew)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		snew[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		snew[i] = s2[j];
		i++;
		j++;
	}
	snew[i] = '\0';
	return (snew);
}
