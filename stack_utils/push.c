/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:09:40 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 13:57:56 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	pa(t_stacks *stacks)
{
	t_stack	*b_push;

	if (!stacks || !stacks->b)
		return ;
	b_push = stacks->b;
	if (stacks->b->next == stacks->b)
		stacks->b = NULL;
	else
	{
		stacks->b->next->previous = stacks->b->previous;
		stacks->b->previous->next = stacks->b->next;
		stacks->b = stacks->b->next;
	}
	stack_add_front(&(stacks->a), b_push);
	stacks->pa++;
	write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks)
{
	t_stack	*a_push;

	if (!stacks || !stacks->a)
		return ;
	a_push = stacks->a;
	if (stacks->a->next == stacks->a)
		stacks->a = NULL;
	else
	{
		stacks->a->next->previous = stacks->a->previous;
		stacks->a->previous->next = stacks->a->next;
		stacks->a = stacks->a->next;
	}
	stack_add_front(&(stacks->b), a_push);
	stacks->pb++;
	write(1, "pb\n", 3);
}
