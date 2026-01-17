/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:32:35 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 15:34:59 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "check_error.h"
#include "flags.h"
#include <unistd.h>

static int	push_swap(char **tab, int len, int mod)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (mod == -1)
		return (0);
	stacks = init_stacks(len, tab, mod);
	if (!stacks)
		return (0);
	indexer(stacks);
	if (!check_order(stacks->a))
		flags(stacks);
	if (stacks->bench == 1)
		print_bench(stacks);
	free_all(stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	char	**tab;
	int		mod;
	int		len;

	if (argc < 2)
		return (0);
	tab = split_all(join_all(argc, argv));
	if (!tab)
		return (0);
	len = len_split(tab);
	mod = calcul_mod(len, tab);
	if (check_error(tab, mod))
		push_swap(tab, len, mod);
	else
		write(2, "Error\n", 6);
	free_tab(tab);
	return (0);
}
