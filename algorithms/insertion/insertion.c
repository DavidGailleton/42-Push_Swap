/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:38:52 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/12 11:30:40 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	nearest_below(t_stack *stack, t_stack *node, int len)
{
	t_stack	*nearest;
	int		nearest_i;
	int 	i;

	nearest = stack;
	i = 1;
	nearest_i = 0;
	stack = stack->next;
	while (i < len)
	{
		if (node->value - stack->value >= 0
			&& node->value - stack->value <= node->value - nearest->value)
		{
			nearest_i = i;
			nearest = stack;
		}
		stack = stack->next;
		i++;
	}
	return (nearest_i);
}

static int	lowest_stack(t_stack *stack, int len)
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
		if (stack->value <= lowest->value)
		{
			lowest_i = i;
			lowest = stack;
		}
		stack = stack->next;
		i++;
	}
	return (lowest_i);
}

static int	rb_to_insert(t_stack *stack_b, t_stack *stack_a, int b_len)
{
	int	i;

	i = 0;
	if (is_lowest(stack_b, stack_a, b_len))
		return (lowest_stack(stack_b, b_len));
	if (is_highest(stack_b, stack_a, b_len))
		return (lowest_stack(stack_b, b_len) + 1);
	return (nearest_below(stack_b, stack_a, b_len) + 1);
}

void	insertion(t_stacks *stacks, int a_len, int b_len)
{
	int	temp;

	if (a_len == 0)
	{
		iterate_fn(stacks, b_len, &pa);
		a_len = b_len;
		temp = lowest_stack(stacks->a, a_len);
		optimal_rotate(stacks, temp, a_len, 'a');
		return ;
	}
	if (b_len == 0)
		pb(stacks);
	else
	{
		temp = rb_to_insert(stacks->b, stacks->a, b_len);
		optimal_rotate(stacks, temp, b_len, 'b');
		pb(stacks);
	}
	//write(1, "pb\n", 3);
	print_stacks(stacks, highest_stack_len(stacks), stacks->a, stacks->b);
	insertion(stacks, a_len - 1, b_len + 1);
}

