/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:39:29 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 16:07:29 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "flags.h"

static int	verif_arg(char *argv)
{
	int		len;
	int		verif;
	char	**split;

	split = ft_split(argv, ' ');
	if (!split)
		return (-1);
	len = len_split(split);
	if (len > 1)
		verif = 1;
	else
		verif = 0;
	free_tab(split);
	return (verif);
}

int	calcul_mod(int argc, char **argv)
{
	int	mod;

	if (verif_arg(argv[argc -1]) == 0)
	{
		if (ft_strncmp("--", argv[1], 2) && ft_strncmp("--", argv[2], 2))
			mod = 2;
		else if (ft_strncmp("--", argv[1], 2) && !ft_strncmp("--", argv[2], 2))
			mod = 1;
		else
			mod = 0;
	}
	else if (verif_arg(argv[argc -1]) == 1)
	{
		if (ft_strncmp("--", argv[1], 2) && ft_strncmp("--", argv[2], 2))
			mod = 5;
		else if (ft_strncmp("--", argv[1], 2) && !ft_strncmp("--", argv[2], 2))
			mod = 4;
		else
			mod = 3;
	}
	else
		mod = -1;
	return (mod);
}

int	pos_flag(char **argv, int mod)
{
	if (mod == 1 || mod == 4)
	{
		if (!ft_strncmp(argv[1], "--bench", 20))
			return (1);
	}
	else if (mod == 2 || mod == 5)
	{
		if (!ft_strncmp(argv[1], "--bench", 20))
			return (1);
		else
			return (2);
	}
	return (0);
}

int	pos_bench(char **argv, int mod)
{
	if (mod == 1 || mod == 4)
	{
		if (ft_strncmp(argv[1], "--bench", 20))
			return (1);
	}
	else if (mod == 2 || mod == 5)
	{
		if (ft_strncmp(argv[1], "--bench", 20))
			return (1);
		else
			return (2);
	}
	return (0);
}

void	flags(int pos, int pos_b, char **argv, t_stacks *stacks)
{
	if (ft_strncmp(argv[pos], "--simple", 30) && pos > 0)
		simple(stacks);
	else if (ft_strncmp(argv[pos], "--medium", 30) && pos > 0)
		medium(stacks);
	else if (ft_strncmp(argv[pos], "--complex", 30) && pos > 0)
		complex(stacks);
	else if (ft_strncmp(argv[pos], "--adaptive", 30) && pos > 0)
		adaptive(stacks, argv);
	else
		adaptive(stacks, argv);
	if (pos_b > 0)
		stacks->bench = 1;
}
