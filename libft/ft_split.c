/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapierre <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:21:51 by mapierre          #+#    #+#             */
/*   Updated: 2022/11/26 20:42:00 by mapierre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

void	free_malloc(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
			i++;
	}
	free(split);
}

int	set_malloc(char const *s, char c, char **split)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				i++;
				j++;
			}
			split[count] = malloc((j + 1) * sizeof(char));
			if (!split[count])
				return (-1);
			count ++;
		}
		else
			i++;
	}
	return (count);
}

void	create_word(char const *s, char c, char **split)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		j = 0;
		if (s[i] != c)
		{
			while (s[i] && s[i] != c)
			{
				split[count][j] = s[i];
				i++;
				j++;
			}
			split[count][j] = '\0';
			count++;
		}
		else
			i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;

	i = count_word(s, c);
	split = malloc((i + 1) * sizeof(split));
	if (!split)
		return (NULL);
	i = set_malloc(s, c, split);
	if (i < 0)
	{
		free_malloc(split);
		return (NULL);
	}
	split[i] = 0;
	if (i > 0)
		create_word(s, c, split);
	return (split);
}
