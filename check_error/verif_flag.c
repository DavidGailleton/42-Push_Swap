/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:51:11 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/09 09:51:12 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	is_exist_flag(char **tab, int pos)
{
	int	verif;

	verif = 0;
	if (ft_strncmp(tab[pos], "--bench", 30)
		|| ft_strncmp(tab[pos], "--simple", 30)
		|| ft_strncmp(tab[pos], "--medium", 30)
		|| ft_strncmp(tab[pos], "--adaptive", 30)
		|| ft_strncmp(tab[pos], "--complex", 30))
		verif = 1;
	return (verif);
}

static int	is_algo_flag(char *str)
{
	if (ft_strncmp(str, "--simple", 30)
		|| ft_strncmp(str, "--medium", 30)
		|| ft_strncmp(str, "--adaptive", 30)
		|| ft_strncmp(str, "--complex", 30))
		return (1);
	return (0);
}

static int	verif_exist_flag(char **tab, int mod)
{
	int	verif;

	verif = 0;
	if (mod == 1)
		verif = (is_exist_flag(tab, 1));
	else if (mod == 2)
	{
		if (is_exist_flag(tab, 1) && is_exist_flag(tab, 2))
			verif = 1;
		if (is_algo_flag(tab[1]) && is_algo_flag(tab[2]))
			verif = 0;
	}
	return (verif);
}

static int	verif_double_flag(char **tab, int mod)
{
	int	verif;

	verif = 1;
	if (mod == 2 && ft_strncmp(tab[1], tab[2], 9))
		verif = 0;
	return (verif);
}

int	verif_flag(char **tab, int mod)
{
	if (mod == 0)
		return (1);
	if (verif_double_flag(tab, mod) && verif_exist_flag(tab, mod))
		return (1);
	return (0);
}
