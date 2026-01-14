/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 15:34:04 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/13 14:55:21 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	len;
	size_t	tester;

	i = 0;
	len = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		tester = 0;
		while (s[i] != c && s[i])
		{
			tester++;
			i++;
		}
		if (tester > 0)
			len++;
	}
	return (len);
}

static size_t	len_word(size_t i, char const *s, char c)
{
	size_t	len;

	len = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		return (len);
	}
	return (len);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**big_tab;

	big_tab = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!big_tab)
		return (0);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			big_tab[j] = ft_substr(s, i, len_word(i, s, c));
			if (!big_tab[j])
				return (free_tab(big_tab), NULL);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	big_tab[j] = 0;
	return (big_tab);
}
