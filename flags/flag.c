/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:39:29 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/07 12:39:31 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"

void	flags(int pos, char **argv, t_stacks *piles)
{
	if (ft_strncmp(argv[pos], "--simple", 30) && pos > 0)
		simple(piles);
	else if (ft_strncmp(argv[pos], "--medium", 30) && pos > 0)
		medium(piles);
	else if (ft_strncmp(argv[pos], "--complex", 30) && pos > 0)
		complex(piles);
	else if (ft_strncmp(argv[pos], "--adaptive", 30) && pos > 0)
		adaptive(piles);
	else
		adaptive(piles);

}
