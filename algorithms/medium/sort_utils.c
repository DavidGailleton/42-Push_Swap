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
#include <stdio.h>
void	move_rr_rrr(t_stacks *stacks, int move, char c)
{
	int	i;

	i = 0;
	while (i < move && c == 's')
	{
		rr(stacks);
		i++;
	}
	while (i < move && c == 'e')
	{
		i++;
		rrr(stacks);
	}
}

void	put_in_order_ra_rra(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (!check_order(stacks->a) && i < 50)
	{
		ra(stacks);
		i++;
	}
}

void	path_rr_rrr(int value, t_stacks *stacks, t_tab *one_preset, int range)
{
	int	move_a;
	int	final_move;
	
	final_move = get_pre_move_b(stacks, one_preset, range);
	if (wich_path_a(value, stacks) == 1
		&& wich_path(stacks, one_preset->max_range, range, 'b'))
	{
		move_a = move_left_to_right(value, stacks, 0);
		if (move_a < final_move)
			final_move = move_a;
		move_rr_rrr(stacks, final_move, 's');
	}
	else if (wich_path_a(value, stacks) == 0
		&& !wich_path(stacks, one_preset->max_range, range, 'b'))
	{
		move_a = move_right_to_left(value, stacks, 0);
		if (move_a < final_move)
			final_move = move_a;
		move_rr_rrr(stacks, final_move, 'e');
	}

}

void	push_range_to_b(t_stacks *stacks, t_tab *one_preset, int range)
{
	int	value;
	int	i;

	i = 0;
	while (one_preset->nb_in > 0)
	{
		if (stacks->a)
		{
			value = get_value_finded(stacks, one_preset, range);
			path_rr_rrr(value, stacks, one_preset, range);
		}
		normal_move_path(stacks, one_preset, range);
		move_ra_rra(stacks->b->index, stacks);
		pa(stacks);
		put_in_order_ra_rra(stacks);
		one_preset->nb_in--;
		i++;
		if (!check_order(stacks->a))
			return ;
	}
}
