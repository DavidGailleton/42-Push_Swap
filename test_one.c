/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.lyon42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:33:58 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/22 12:34:35 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	test1(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (argc > 1)
	{
		stacks = init_big_stacks(argc, argv);
		print_all_stack(stacks->a, stacks->a, 'A');
		print_all_stack(stacks->b, stacks->b, 'B');
		rra(stacks);
		print_all_stack(stacks->a, stacks->a, 'A');
		print_all_stack(stacks->b, stacks->b, 'B');
	}
	if (stacks->a)
		stack_clear_all(stacks->a, stacks->a);
	if (stacks->b)
		stack_clear_all(stacks->b, stacks->b);
	free(stacks);
	return (0);
}

int	test2(char **argv)
{
	int			*tab;
	int			len;
	t_tab		*preset;
	t_stacks	*piles;

	len = ft_atoi(argv[2]);
	if (len < 1)
	{
		printf("WRONG LEN PLS BE SMART.\n");
		return (0);
	}
	tab = auto_shuffle(len);
	piles = init_big_stacks2(tab, len);
	preset = get_tabs(piles->a, range_bucket(piles->a));
	free(tab);
	free_tab(&preset);
	if (piles->a)
		stack_clear_all(piles->a, piles->a);
	if (piles->b)
		stack_clear_all(piles->b, piles->b);
	free(piles);
	return (0);
}
