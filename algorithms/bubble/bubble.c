/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:56:23 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/09 14:09:07 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "unistd.h"

void	bubble_alg(t_stacks *stacks)
{
	while (stack_a_len(stacks))
	{
		if (stacks->a->value > stacks->a->next->value)
		{
			sa(stacks);
			write(1, "sa\n", 3);
		}
		pb(stacks);
		write(1, "pb\n", 3);
		// print_stacks(stacks, highest_stack_len(stacks), stacks->a, stacks->b);
	}
	while (stack_b_len(stacks))
	{
		if (stacks->b->value < stacks->b->next->value)
		{
			sb(stacks);
			write(1, "sa\n", 3);
		}
		pa(stacks);
		write(1, "pb\n", 3);
		// print_stacks(stacks, highest_stack_len(stacks), stacks->a, stacks->b);
	}
	if (check_order(stacks->a))
		return ;
	bubble_alg(stacks);
}
