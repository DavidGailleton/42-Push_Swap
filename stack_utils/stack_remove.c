/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:05:27 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/12 11:39:02 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	stack_clear_all(t_stack *stack, t_stack *first)
{
	if (!stack)
		return ;
	if (stack->next != first)
		stack_clear_all(stack->next, first);
	free(stack);
}

void	free_all(t_stacks *piles)
{
	if (piles->a)
		stack_clear_all(piles->a, piles->a);
	if (piles->b)
		stack_clear_all(piles->b, piles->b);
	free(piles);
}
