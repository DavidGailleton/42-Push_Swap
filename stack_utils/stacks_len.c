/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:11:50 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/09 13:19:21 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_a_len(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*a_stack;
	int		len;

	a_stack = stacks->a;
	first = a_stack;
	if (!a_stack)
		return (0);
	len = 1;
	while (a_stack->next != first)
	{
		a_stack = a_stack->next;
		len++;
	}
	return (len);
}

int	stack_b_len(t_stacks *stacks)
{
	t_stack	*first;
	t_stack	*b_stack;
	int		len;

	b_stack = stacks->b;
	first = b_stack;
	if (!b_stack)
		return (0);
	len = 1;
	while (b_stack->next != first)
	{
		b_stack = b_stack->next;
		len++;
	}
	return (len);
}

int	highest_stack_len(t_stacks *stacks)
{
	int	a_len;
	int	b_len;

	a_len = stack_a_len(stacks);
	b_len = stack_b_len(stacks);
	if (a_len > b_len)
		return (a_len);
	return (b_len);
}
