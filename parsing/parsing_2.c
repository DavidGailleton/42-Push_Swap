/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 08:22:21 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/09 08:22:22 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static char	*free_join(char *tab)
{
	free(tab);
	return (NULL);
}

char	*join_all(int argc, char **argv)
{
	char	*tab;
	char	*tmp;
	int		i;

	i = 0;
	tab = ft_strjoin(argv[i], " ");
	i++;
	if (!tab)
		return (NULL);
	while (i < argc)
	{
		tmp = ft_strjoin(argv[i], " ");
		if (!tmp)
			return (free_join(tab));
		tab = ft_strjoin(tab, tmp);
		if (!tab)
			return (free_join(tmp));
		i++;
	}
	free(tmp);
	return (tab);
}

char	**split_all(char *tab)
{
	char	**split;

	if (!tab)
		return (NULL);
	split = ft_split(tab, ' ');
	if (!split)
		return (NULL);
	return (split);
}
