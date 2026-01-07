/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:47:06 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/07 11:45:50 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	one_higher_than_unit(t_stack *stack, int unit)
{
	t_stack	*temp;

	temp = stack;
	if (stack->value > unit)
		return (1);
	stack = stack->next;
	while (stack != temp)
	{
		if (stack->value > unit)
			return (1);
		stack = stack->next;
	}
	return (0);
}
*/
static int	to_insert(t_stacks *stacks, int value)
{
	int		i;
	int		s_len;
	t_stack	*temp;

	temp = stacks->a;
	if (!stacks->a)
		return (0);
	i = 0;
	s_len = stack_a_len(stacks);
	while (temp->value < value
		&& temp->previous->value > value && s_len >= i)
	{
		if (s_len == i)
			return (r_to_lowest(stacks->a, s_len) + 1);
		i++;
		temp = temp->next;
	}
	return (i);
}

static int	is_contain_lower_unit(t_stack *stack, int unit, int s_len)
{
	int	i;

	i = 0;
	while (i < s_len)
	{
		if (stack->value < unit)
			return (1);
		i++;
		stack = stack->next;
	}
	return (0);
}

static void	rec_sort(t_stacks *stacks, int unit)
{
	if (!stacks->b)
		return ;
	while (is_contain_lower_unit(stacks->b, unit, stack_b_len(stacks)))
	{
		if (stacks->b->value < unit)
		{
		optimal_rotate(stacks, to_insert(stacks, stacks->b->value)
				, stack_a_len(stacks), 'a');
		pa(stacks);
		}
		else
			rb(stacks);
	}
	rec_sort(stacks, unit * 10);
}

void	radix(t_stacks *stacks)
{
	while (stacks->a)
		pb(stacks);
	rec_sort(stacks, 10);
}
