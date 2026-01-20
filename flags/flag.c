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
	while (argv[mod] && !ft_isdigit(argv[mod][0])
			&& !ft_isdigit(argv[mod][1]) && argv[mod][1] && mod < argc)
		mod++;
	mod--;
	return (mod);
}

void	flags(t_stacks *stacks)
{
	if (stacks->algo == 1)
		simple(stacks);
	else if (stacks->algo == 2)
		medium(stacks);
	else if (stacks->algo == 3)
		complex(stacks);
	else
		adaptive(stacks);
}
