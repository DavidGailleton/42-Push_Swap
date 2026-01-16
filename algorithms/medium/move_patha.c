/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_patha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 06:20:47 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/16 06:20:55 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "medium_headers.h"
#include "push_swap.h"
#include <stdio.h>
static int	is_border_a(int value, t_stacks *stacks)
{
	t_stack	*tmp;

	if (!stacks->a)
		return (1);
	tmp = assign_stack(stacks, 'a');
	if ((value < tmp->index && check_order(tmp))
		|| (value > tmp->index && value > tmp->previous->index
		&& check_order(stacks->a)))
		return (1);
	return (0);
}

int	move_left_to_right(int value, t_stacks *stacks, int is_move)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = assign_stack(stacks, 'a');
	while (value > tmp->index && !is_move)
	{
		tmp = tmp->next;
		i++;
	}
	while (value > stacks->a->index && is_move)
		ra(stacks);
	return (i);
}

int	move_right_to_left(int value, t_stacks *stacks, int is_move)
{
	int		i;
	t_stack	*tmp;

	tmp = assign_stack(stacks, 'a');
	i = 0;
	while (value < tmp->previous->index && !is_move)
	{
		tmp = tmp->previous;
		i++;
	}
	while (value < stacks->a->previous->index && is_move)
		rra(stacks);
	return (i);
}

int	wich_path_a(int value, t_stacks *stacks)
{
	t_stack	*tmp;
	int		move_from_left;
	int		move_from_right;

	tmp = assign_stack(stacks, 'a');
	if (is_border_a(value, stacks))
		return (-1);
	move_from_left = move_left_to_right(value, stacks, 0);
	move_from_right = move_right_to_left(value, stacks, 0);
	if ((check_order(stacks->a) && move_from_left < move_from_right)
		|| (move_from_left > move_from_right && !check_order(stacks->a)))
		return (1);
	else
		return (0);
}

void	move_ra_rra(int value, t_stacks *stacks)
{
	if (is_border_a(value, stacks))
		return ;
	if (wich_path_a(value, stacks) == 1)
	{
		move_left_to_right(value, stacks, 1);
	}
	else if (wich_path_a(value, stacks) == 0)
	{
		move_right_to_left(value, stacks, 1);
	}
}
