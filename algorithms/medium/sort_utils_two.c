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
#include "medium_headers.h"

static void	medium_pus_to_a(t_stacks *stacks, t_tab *one_preset, int range)
{
	int	i;

	i = 0;
	while (one_preset->nb_in > i)
	{
		if (wich_path(stacks, one_preset->max_range, range, 'a'))
		{
			while (!in_range(stacks->b->value, one_preset->max_range, range))
				ra(stacks);
		}
		else
		{
			while (!in_range(stacks->b->value, one_preset->max_range, range))
				rra(stacks);
		}
		pb(stacks);
		i++;
	}
}

void	medium_pre_sort(t_stacks *stacks, t_tab *preset, int range)
{
	t_tab	*tmp;

	tmp = preset;
	while (preset)
	{
		medium_pus_to_a(stacks, tmp, range);
		tmp = tmp->next;
	}
}

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

t_stack	*assign_stack(t_stacks *stacks, char c)
{
	t_stack	*tmp;

	if (c == 'a')
		tmp = stacks->a;
	else
		tmp = stacks->b;
	return (tmp);
}
