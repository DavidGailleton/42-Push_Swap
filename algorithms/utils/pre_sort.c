/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 14:21:20 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/15 14:59:52 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_to_lowest(t_stack *stack, int len)
{
	t_stack	*lowest;
	int		lowest_i;
	int		i;

	i = 1;
	lowest_i = 0;
	lowest = stack;
	stack = stack->next;
	while (i < len)
	{
		if (stack->value < lowest->value)
		{
			lowest_i = i;
			lowest = stack;
		}
		stack = stack->next;
		i++;
	}
	return (lowest_i);
}

void	sort_two(t_stacks *stacks)
{
	sa(stacks);
}

void	sort_three_a(t_stacks *stacks)
{
	if (check_order(stacks->a))
		return ;
	if (stacks->a->value > stacks->a->next->value)
		sa(stacks);
	optimal_rotate(stacks, r_to_lowest(stacks->a, 3), 3, 'a');
	if (stacks->a->next->value > stacks->a->previous->value)
	{
		ra(stacks);
		sa(stacks);
		rra(stacks);
	}
}
