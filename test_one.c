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

int test1(int argc, char **argv)
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
	return (0);
}

int test2(char **argv){

	int			*tab;
	int			len;
	t_tab		*preset;
	t_stacks	*piles;
	int			i;

	i = 0;
	len = ft_atoi(argv[2]);
	if (len < 1)
	{
		printf("WRONG LEN PLS BE SMART.\n");
		return (0);
	}
	tab = auto_shuffle(len);
	while (i < len)
	{
		printf("tab(%d) [%d]\n", i, tab[i]);
		i++;
	}
	piles = init_big_stacks2(tab, len);
	printf("RANGE BUCKET %d\n", range_bucket(piles->a));
	preset = get_tabs(piles->a, range_bucket(piles->a));
	print_tabs(preset);
	free(tab);
	free_tab(preset);
	return (0);
}