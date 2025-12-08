/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:05:27 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/08 16:15:28 by dgaillet         ###   ########lyon.fr   */
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
