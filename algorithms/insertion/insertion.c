/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:38:52 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/14 16:51:05 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	to_insert(t_stacks *stacks, int sorted)
{
	int		i;
	t_stack	*a;

	i = 0;
	a = stacks->a;
	while (i < sorted)
	{
		if (stacks->b->value > a->previous->value)
			return (i);
		a = a->previous;
		i++;
	}
	return (i);
}

void	insertion(t_stacks *stacks, int sorted, int len)
{
	int	to_r_rotate;

	if (sorted >= len)
		return ;
	if (sorted == 0)
		ra(stacks);
	else
	{
		pb(stacks);
		to_r_rotate = to_insert(stacks, sorted);
		optimal_rotate(stacks, len - to_r_rotate - 1, len - 1, 'a');
		pa(stacks);
		optimal_rotate(stacks, to_r_rotate, len, 'a');
		ra(stacks);
	}
	insertion(stacks, sorted + 1, len);
}
/*
void	insertion(t_stacks *stacks, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		pb(stacks);
		i++;
	}
}
*/
/*
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
	//print_stacks(stacks, highest_stack_len(stacks), stacks->a, stacks->b);
	insertion(stacks, a_len - 1, b_len + 1);
}
*/
