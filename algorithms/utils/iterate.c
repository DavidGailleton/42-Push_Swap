/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:49:56 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/15 14:44:56 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	iterate_fn(t_stacks *stacks, int i, void (f)(t_stacks *stacks))
{
	while (i > 0)
	{
		f(stacks);
		i--;
	}
}

void	optimal_rotate(t_stacks *stacks, int i, int len, char stack)
{
	if (i == len)
		return ;
	if (i && len / i >= 2)
	{
		if (stack == 'a')
			iterate_fn(stacks, i, &ra);
		else
			iterate_fn(stacks, i, &rb);
	}
	else if (i)
	{
		if (stack == 'a')
			iterate_fn(stacks, len - i, &rra);
		else
			iterate_fn(stacks, len - i, &rrb);
	}
}
