/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:09:40 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/08 15:28:53 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	t_stack	a;

	if (!stacks || !stacks->b)
		return ;
	a = stack->a;
	a-value = stacks->b->value;
}

void	pb(t_stacks *stacks)
{
	t_stack	b;

	if (!stacks || !stacks->a)
		return ;
	b = stacks->b;
	b->value = stacks->a->value;
}
