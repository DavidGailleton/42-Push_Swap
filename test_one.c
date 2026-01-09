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
#include <stdlib.h>

int	test1(int argc, char **argv)
{
	t_stacks	*stacks;
	int			mod;
	char		**tab;
	int			len;

	stacks = NULL;
	tab = split_all(join_all(argc, argv));
	if (!tab)
		return (0);
	len = len_split(tab);
	mod = calcul_mod(len, tab);
	if (mod == -1)
		return (0);
	stacks = init_stacks(len, tab, mod);
	if (!stacks)
		return (0);
	if (check_order(stacks->a))
		return (0);
	flags(pos_flag(tab, mod), pos_bench(tab, mod), tab, stacks);
	if (stacks->bench == 1)
		print_bench(stacks);
	free_all(stacks);
	return (0);
}
