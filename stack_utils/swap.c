/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:48:44 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 13:58:13 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sa(t_stacks *stacks)
{
	t_stack	*a;
	int		stock;

	if (!stacks || !stacks->a || !stacks->a->next)
		return ;
	a = stacks->a;
	stock = a->value;
	a->value = a->next->value;
	a->next->value = stock;
	stacks->sa++;
	if (stacks->print)
		write(1, "sa\n", 3);
}

void	sb(t_stacks *stacks)
{
	t_stack	*b;
	int		stock;

	if (!stacks || !stacks->b || !stacks->b->next)
		return ;
	b = stacks->b;
	stock = b->value;
	b->value = b->next->value;
	b->next->value = stock;
	stacks->sb++;
	if (stacks->print)
		write(1, "sb\n", 3);
}

void	ss(t_stacks *stacks)
{
	t_stack	*b;
	t_stack	*a;
	int		stock;

	if (!stacks)
		return ;
	if (stacks->b && stacks->b->next)
	{
		b = stacks->b;
		stock = b->value;
		b->value = b->next->value;
		b->next->value = stock;
	}
	if (stacks->a && stacks->a->next)
	{
		a = stacks->a;
		stock = a->value;
		a->value = a->next->value;
		a->next->value = stock;
	}
	stacks->ss++;
	if (stacks->print)
		write(1, "ss\n", 3);
}
