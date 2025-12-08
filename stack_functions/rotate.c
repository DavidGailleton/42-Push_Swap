/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:32:10 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/08 14:42:04 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->a->next)
		stacks->a = stacks->a->next;
}

void	rb(t_stacks *stacks)
{
	if (!stacks)
		return ;
	if (stacks->b->next)
		stacks->b = stacks->b->next;
}

void	rr(t_stacks *stacks)
{
	ra(stacks);
	rb(stacks);
}
