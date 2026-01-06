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
	while (one_preset->nb_in > 0)
	{
		if (wich_path(piles, one_preset->max_range, range, 'b'))
		{
			while (!in_range(piles->b->value, one_preset->max_range, range))
				rb(piles);
		}
		else
		{
			while (!in_range(piles->b->value, one_preset->max_range, range))
			{
				rrb(piles);
			}
		}
		sort_little_pile(piles);
		one_preset->nb_in--;
	}
	print_all_stack(piles->a, piles->a, 'A');
	print_all_stack(piles->b, piles->b, 'B');
}

int	sort_path(t_stacks *piles, int value)
{
	int	start_path;
	int	end_path;

	start_path = number_move_reverse(piles, value, 's');
	if (start_path == 0)
		return (1);
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
	tmp = piles->a;
	if (start_end == 's')
	{
		while (tmp->value < value)
		{
			tmp = tmp->next;
			i++;
		}
	}
	else
	{
		tmp = tmp->previous;
		while (tmp->value > value)
		{
			tmp = tmp->previous;
			i++;
		}
	}
	return (i);
}

void	sort_little_pile(t_stacks *piles)
{
	if (!piles->a)
	{
		pa(piles);
		return ;
	}
	if (piles->a->previous->value < piles->b->value)
	{
		pa(piles);
		ra(piles);
		return ;
	}
	if (sort_path(piles, piles->b->value))
		sort_from_left(piles);
	else
		sort_from_right(piles);
}
