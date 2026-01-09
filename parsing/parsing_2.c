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

static char	*join_utils(char *start_tab, char *end_str)
{
	char	*tab;
	char	*tmp2;

	tmp2 = ft_strjoin(end_str, " ");
	if (!tmp2)
		return (free_join(start_tab));
	tab = ft_strjoin(start_tab, tmp2);
	free(start_tab);
	free(tmp2);
	return (tab);
}

char	*join_all(int argc, char **argv)
{
	char	*tab;
	int		i;

	i = 0;
	tab = ft_strjoin(argv[i], " ");
	i++;
	if (!tab)
		return (NULL);
	while (i < argc)
	{
		tab = join_utils(tab, argv[i]);
		i++;
	}
	return (tab);
}

char	**split_all(char *tab)
{
	char	**split;

	if (!tab)
		return (NULL);
	split = ft_split(tab, ' ');
	free (tab);
	if (!split)
		return (NULL);
	return (split);
}
