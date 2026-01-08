/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.lyon42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:33:58 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 15:35:43 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "flags.h"
#include "parsing.h"
#include "medium_headers.h"
#include <stdio.h>
#include <stdlib.h>

int	test1(int argc, char **argv)
{
	t_stacks	*piles;
	int			mod;

	piles = NULL;
	mod = calcul_mod(argc, argv);
	piles = init_piles(argc, argv, mod);
	if (check_order(piles->a))
		return (0);
	flags(pos_flag(argv, mod), pos_bench(argv, mod), argv, piles);
	if (piles->bench == 1)
		print_bench(piles);
	free_all(piles);
	return (0);
}
