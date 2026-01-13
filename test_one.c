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

int	test1(char **tab, int len, int mod)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (mod == -1)
		return (0);
	stacks = init_stacks(len, tab, mod);
	if (!stacks)
		return (0);
	if (check_order(stacks->a))
	{
		free_all(stacks);
		return (0);
	}
	stacks->disorder = compute_disorder(tab, wich_mod(mod));
	flags(pos_flag(tab, mod), pos_bench(tab, mod), tab, stacks);
	if (stacks->bench == 1)
		print_bench(stacks);
	free_all(stacks);
	return (0);
}
