/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:38:52 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/14 17:31:02 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	r_to_lowest(t_stack *stack, int len)
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

static int	to_insert(t_stacks *stacks, int sorted)
{
	int		i;
	t_stack	*a;

	if (is_lowest(stacks->a, stacks->b, sorted)
		|| is_highest(stacks->a, stacks->b, sorted))
		return (sorted - r_to_lowest(stacks->a, sorted));
	i = 0;
	a = stacks->a;
	while (i < sorted)
	{
		if (stacks->b->value > a->previous->value && stacks->b->value <= a->value)
			return (i);
		a = a->previous;
		i++;
	}
	return (i);
}

static void	ft_extra(t_stacks *stacks, int sorted, int b_len)
{
	int	to_r_rotate;

	if (b_len <= 0)
		return ;
	if (sorted <= 1)
		pa(stacks);
	else
	{
		to_r_rotate = to_insert(stacks, sorted);
		optimal_rotate(stacks, sorted - to_r_rotate, sorted, 'a');
		pa(stacks);
	}
	ft_extra(stacks, sorted + 1, b_len - 1);
}

void	insertion(t_stacks *stacks, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		pb(stacks);
		i++;
	}
	ft_extra(stacks, 0, len);
	optimal_rotate(stacks, r_to_lowest(stacks->a, len), len, 'a');
}
