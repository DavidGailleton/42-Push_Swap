/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 07:52:36 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/06 07:52:38 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_from_left(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->b->value > stacks->a->value)
	{
		ra(stacks);
		i++;
	}
	pa(stacks);
	while (i > 0)
	{
		rra(stacks);
		i--;
	}
}

void	sort_from_right(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (stacks->b->value < stacks->a->previous->value)
	{
		rra(stacks);
		i++;
	}
	pa(stacks);
	while (i >= 0)
	{
		ra(stacks);
		i--;
	}
}
