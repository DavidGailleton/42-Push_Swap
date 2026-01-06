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

void	sort_from_left(t_stacks *piles)
{
	int	i;

	i = 0;
	while (piles->b->value > piles->a->value)
	{
		ra(piles);
		i++;
	}
	pa(piles);
	while (i > 0)
	{
		rra(piles);
		i--;
	}
}

void	sort_from_right(t_stacks *piles)
{
	int	i;

	i = 0;
	while (piles->b->value < piles->a->previous->value)
	{
		rra(piles);
		i++;
	}
	pa(piles);
	while (i >= 0)
	{
		ra(piles);
		i--;
	}
}
