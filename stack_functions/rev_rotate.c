/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:43:45 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/08 14:50:40 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks)
{
	if (stacks->a && stacks->a->previous)
		stacks->a = stacks->a->previous;
}

void	rrb(t_stacks *stacks)
{
	if (stacks->b && stacks->b->previous)
		stacks->b = stacks->b->previous;
}

void	rrr(t_stacks *stacks)
{
	rra(stacks);
	rrb(stacks);
}
