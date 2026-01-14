/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 10:14:06 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/14 10:14:08 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*first_without_index(t_stack *stack)
{
	t_stack	*first;

	if (stack->index < 0)
		return (stack);
	first = stack;
	stack = stack->next;
	while (stack != first)
	{
		if (stack->index < 0)
			return (stack);
		stack = stack->next;
	}
	return ((void *) 0);
}

void	indexer(t_stacks *stacks)
{
	int		i;
	int		len;
	t_stack	*lower;
	t_stack	*temp;

	i = 0;
	len = stack_a_len(stacks);
	while (i < len)
	{
		lower = first_without_index(stacks->a);
		temp = lower->next;
		while (temp != stacks->a)
		{
			if (lower->value > temp->value && temp->index < 0)
				lower = temp;
			temp = temp->next;
		}
		lower->index = i;
		i++;
	}
}
