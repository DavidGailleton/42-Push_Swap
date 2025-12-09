/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 11:56:23 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/09 12:43:09 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_alg(t_stacks *stacks)
{
	while (!check_order(stacks->a))
	{
		if (stacks->a->value > stacks->a->next->value)
			sa(stacks);
		ra(stacks);
	}
}
