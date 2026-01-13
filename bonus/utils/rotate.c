/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:32:10 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/08 13:57:47 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	ra(t_stacks *stacks)
{
	if (stacks && stacks->a && stacks->a->next)
		stacks->a = stacks->a->next;
}

void	rb(t_stacks *stacks)
{
	if (stacks && stacks->b && stacks->b->next)
		stacks->b = stacks->b->next;
}

void	rr(t_stacks *stacks)
{
	if (stacks && stacks->a && stacks->a->next)
		stacks->a = stacks->a->next;
	if (stacks && stacks->b && stacks->b->next)
		stacks->b = stacks->b->next;
}
