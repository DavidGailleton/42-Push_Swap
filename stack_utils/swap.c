/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:48:44 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/08 19:40:49 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
}

void	ss(t_stacks *stacks)
{
	sa(stacks);
	sb(stacks);
}
