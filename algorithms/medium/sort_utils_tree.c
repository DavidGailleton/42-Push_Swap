/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_tree.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:20:06 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/15 12:20:07 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "medium_headers.h"
#include <stdio.h>

void	opti2_move_path(t_stacks *stacks, t_tab *one_preset, int range)
{
	int	value;
	int	len;

	value = stacks->b->value;
	len = stack_a_len(stacks);
	if (in_range(value, one_preset->max_range, range) && len > 0)
	{
		while (value < stacks->a->previous->value && !check_order(stacks->a))
			rra(stacks);
	}
}
static int	get_pre_move_b(t_stacks *stacks, t_tab *one_preset, int range)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = assign_stack(stacks, 'b');
	if (wich_path(stacks, one_preset->max_range, range, 'b'))
	{
		while (!in_range(tmp->value, one_preset->max_range, range))
		{
			i++;
			tmp = tmp->next;
		}
	}
	else
		while (!in_range(tmp->value, one_preset->max_range, range))
		{
			i++;
			tmp = tmp->previous;
		}
	return (i);
}

static int	get_pre_move_a(t_stacks *stacks, int val)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = assign_stack(stacks, 'a');
	if (sort_path(stacks, val))
	{
		while (val > tmp->value)
		{
			i++;
			tmp = tmp->next;
		}
	}
	else
	{
		tmp = tmp->previous;
		while (val < tmp->value)
		{
			i++;
			tmp = tmp->previous;
		}
	}
	return (i);
}

static int	get_min_move(t_stacks *stacks, t_tab *one_preset, int range, int val)
{
	int	b;
	int	a;
	a = get_pre_move_a(stacks, val);
	b = get_pre_move_b(stacks, one_preset, range);
	if (a < b)
		return (a);
	else
		return (b);
}

void	opti_path(t_stacks *stacks, t_tab *one_preset, int range, int val)
{
	int	move;
	int	i;

	i = 0;
	if (sort_path(stacks, val)
		&& wich_path(stacks, one_preset->max_range, range, 'b'))
	{
		move = get_min_move(stacks, one_preset, range, val);
		while (i < move)
		{
			rr(stacks);
			i++;
		}
	}
	else if (!sort_path(stacks, val)
		&& !wich_path(stacks, one_preset->max_range, range, 'b'))
	{
		move = get_min_move(stacks, one_preset, range, val);
		while (i < move)
		{
			rrr(stacks);
			i++;
		}
	}
}
