/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:46:00 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/11 17:46:22 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_lowest(t_stack *stack, t_stack *node, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (node->value > stack->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}

int	is_highest(t_stack *stack, t_stack *node, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (node->value < stack->value)
			return (0);
		stack = stack->next;
		i++;
	}
	return (1);
}


