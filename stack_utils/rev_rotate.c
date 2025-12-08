/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:43:45 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/08 14:52:53 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	if (stacks && stacks->a && stacks->a->previous)
		stacks->a = stacks->a->previous;
}

void	rrb(t_stacks *stacks)
{
	if (stacks && stacks->b && stacks->b->previous)
		stacks->b = stacks->b->previous;
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
