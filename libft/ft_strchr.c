/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:04:20 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/21 21:38:18 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return (((char *)s) + i);
		i++;
	}
	if (s[i] == (unsigned char)c)
		return (((char *)s) + i);
	return (0);
}
/*
int main(void)
{
	printf("%s", ft_strchr("coucou", 'u'));
}*/
