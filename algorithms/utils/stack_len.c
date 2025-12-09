/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 12:05:15 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/09 12:07:29 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_len(t_stack *stack)
{
	t_stack	*first;
	int		i;

	first = stack;
	if (!stack)
		return (0);
	i = 1;
	while (stack->next != first)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
