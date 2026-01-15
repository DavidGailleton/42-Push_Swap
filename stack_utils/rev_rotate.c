/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:43:45 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/08 13:57:27 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	rra(t_stacks *stacks)
{
	if (stacks && stacks->a && stacks->a->previous)
		stacks->a = stacks->a->previous;
	stacks->rra++;
	if (stacks->print)
		secure_write(1, "rra\n", 4);
}

void	rrb(t_stacks *stacks)
{
	if (stacks && stacks->b && stacks->b->previous)
		stacks->b = stacks->b->previous;
	stacks->rrb++;
	if (stacks->print)
		secure_write(1, "rrb\n", 4);
}

void	rrr(t_stacks *stacks)
{
	if (stacks && stacks->b && stacks->b->previous)
		stacks->b = stacks->b->previous;
	if (stacks && stacks->a && stacks->a->previous)
		stacks->a = stacks->a->previous;
	stacks->rrr++;
	if (stacks->print)
		secure_write(1, "rrr\n", 4);
}
