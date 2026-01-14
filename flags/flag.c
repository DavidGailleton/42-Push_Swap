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

int	calcul_mod(int argc, char **argv)
{
	int	mod;

	mod = 0;
	while (argv[mod] && !ft_isdigit(argv[mod][0]) && mod < argc)
		mod++;
	mod--;
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
	{
		stacks->algo = 1;
		simple(stacks);
	}
	else if (ft_strncmp(argv[pos], "--medium", 30) && pos > 0)
	{
		stacks->algo = 2;
		medium(stacks);
	}	
	else if (ft_strncmp(argv[pos], "--complex", 30) && pos > 0)
	{
		stacks->algo = 3;
		complex(stacks);
	}	
	else if (ft_strncmp(argv[pos], "--adaptive", 30) && pos > 0)
		adaptive(stacks, argv);
	else
		adaptive(stacks, argv);
	if (pos_b > 0)
		stacks->bench = 1;
}
