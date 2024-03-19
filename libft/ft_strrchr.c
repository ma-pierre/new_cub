/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:18:39 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/21 21:52:47 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return (((char *)s) + i);
		i--;
	}
	return (0);
}
/*
int main(void)
{
	printf("%s, ---", ft_strrchr("abcdefgh", 'g'));
	printf("%s, ---", ft_strrchr("abcdefgh", 'h'));
	printf("%s, ---", ft_strrchr("abcdefgh", 'a'));
	printf("%s", ft_strrchr("abcdefgh", 'u'));
}*/
