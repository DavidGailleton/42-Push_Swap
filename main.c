/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:32:35 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/09 11:39:55 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_all_stack(t_stack *stack, t_stack *first, char pile)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	printf("TAB %c : \n", pile);
	if (!stack || !first)
		return ;
	while (tmp->next != first)
	{
		printf("[%d] ", tmp->value);
		tmp = tmp->next;
		i++;
	}
	printf("[%d] \n", tmp->value);
}

int	main(int argc, char **argv)
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
}
