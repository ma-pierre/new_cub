/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:31:41 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/21 22:27:58 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	setcount(char froms1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (froms1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	i = 0;
	start = 0;
	while (setcount(s1[i++], set) == 1)
		start++;
	while (s1[i])
		i++;
	end = 0;
	while (setcount(s1[--i], set) == 1)
		end++;
	i = ft_strlen(s1);
	i -= (start + end);
	str = malloc((i + 1) * sizeof (char));
	if (!str)
		return (0);
	end = (i + start);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
