/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 14:11:49 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/05 14:11:52 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_range_to_b(t_stacks *piles, t_tab *one_preset, int range)
{
	t_stack	*a;
	t_stack	*b;

	a = piles->a;
	b = piles->b;
	while (one_preset->nb_in > 0)
	{
		if (wich_path(piles, one_preset->max_range, range, 'a'))
		{
			while (!in_range(a->value))
				ra(piles);
		}
		else
			while (!in_range(a->value))
				rra(piles);
		pb(piles);		
	}
}

int	sort_path(t_stacks *piles, int value)
{
	int start_path;
	int	end_path;

	start_path = number_move_reverse(piles, value, 's');
	end_path = number_move_reverse(piles, value, 'e');
	if (start_path < end_path)
		return (1);
	return (0);
}

int	number_move_reverse(t_stacks *piles, int value, char start_end)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = piles->b;
	if (start_end  == 's')
	{
		while(tmp->value > value)
		{
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		tmp = tmp->previous;
		while(tmp->value < value)
		{
			tmp = tmp->previous;
			i++;
		}
	}
	return (i);
}

void	sort_little_pile(t_stacks *piles)
{
	int	i;

	i = 0;
	if (!piles->b)
	{
		pb(piles);
		return ;
	}
	if (piles->b->previous->value < piles->a->value)
	{
		pb(piles);
		rb(piles);
		return ;
	}
	if (sort_path(piles, piles->a->value))
		//you stop here
}
