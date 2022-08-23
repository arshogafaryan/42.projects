/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argafary <argafary@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 19:41:38 by argafary          #+#    #+#             */
/*   Updated: 2022/03/13 19:51:41 by argafary         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbofwords(char *s, char c)
{
	int	i;
	int	is_word;

	i = 0;
	is_word = 0;
	while (*s)
	{
		if (is_word == 0 && *s != c)
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (i);
}

static int	ft_lenofword(char *s, char c)
{
	int	len;

	len = 0;
	while (*s != c & *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

static void	*my_free(char **tab, int i)
{
	while (i-- > 0)
	{
		free(tab[i]);
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		nb_ofwords;
	char	**tab;

	i = 0;
	nb_ofwords = ft_nbofwords((char *)s, c);
	tab = (char **)malloc((nb_ofwords * sizeof(char *) + 1));
	if (!tab)
		return (NULL);
	while (nb_ofwords--)
	{
		while (*s == c && *s)
			s++;
		tab[i] = ft_substr((char *)s, 0, ft_lenofword((char *)s, c));
		if (!tab[i])
			return (my_free(tab, i));
		s = s + ft_lenofword((char *)s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
