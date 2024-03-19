/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:49:10 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/21 22:17:44 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"
/*int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	j = ft_strlen(s);
	if (len > j - start)
		len = j - start;
	if (!s || (j < start))
		return (ft_strdup(""));
	str = malloc((len + 1) * sizeof (char));
	if (!str)
		return (0);
	j = start;
	i = 0;
	while (s[j] && i < len)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main(void)
{
	printf("%s", ft_substr("abcdefghijklm", 3, 10));
}*/
