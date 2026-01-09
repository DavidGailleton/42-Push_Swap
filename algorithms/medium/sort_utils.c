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
#include "medium_headers.h"

static int	number_move_reverse(t_stacks *stacks, int value, char start_end)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = stacks->a;
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

static int	sort_path(t_stacks *stacks, int value)
{
	int	start_path;
	int	end_path;

	start_path = number_move_reverse(stacks, value, 's');
	if (start_path == 0)
		return (1);
	end_path = number_move_reverse(stacks, value, 'e');
	if (start_path < end_path)
		return (1);
	return (0);
}

static void	sort_little_pile(t_stacks *stacks)
{
	if (!stacks->a)
	{
		pa(stacks);
		return ;
	}
	if (stacks->a->previous->value < stacks->b->value)
	{
		pa(stacks);
		ra(stacks);
		return ;
	}
	if (sort_path(stacks, stacks->b->value))
		sort_from_left(stacks);
	else
		sort_from_right(stacks);
}

void	push_range_to_b(t_stacks *stacks, t_tab *one_preset, int range)
{
	while (one_preset->nb_in > 0)
	{
		if (wich_path(stacks, one_preset->max_range, range, 'b'))
		{
			while (!in_range(stacks->b->value, one_preset->max_range, range))
				rb(stacks);
		}
		else
		{
			while (!in_range(stacks->b->value, one_preset->max_range, range))
			{
				rrb(stacks);
			}
		}
		sort_little_pile(stacks);
		one_preset->nb_in--;
	}
}
