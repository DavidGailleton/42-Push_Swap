/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_pathb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 06:20:38 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/16 06:20:42 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "medium_headers.h"
#include "push_swap.h"

static int	path_to_end(t_stacks *stacks, int max_range, int range, char c)
{
	t_stack	*tmp;
	t_stack	*start;
	int		i;
	int		first_pass;

	tmp = assign_stack(stacks, c);
	start = assign_stack(stacks, c);
	tmp = tmp->previous;
	i = 0;
	first_pass = 1;
	while (first_pass || tmp != start->previous)
	{
		first_pass = 0;
		if (in_range(tmp->value, max_range, range))
			tmp = start;
		tmp = tmp->previous;
		i++;
	}
	return (i);
}

static int	path_to_start(t_stacks *stacks, int max_range, int range, char c)
{
	t_stack	*tmp;
	t_stack	*start;
	int		i;
	int		first_pass;

	tmp = assign_stack(stacks, c);
	start = assign_stack(stacks, c);
	i = 0;
	first_pass = 1;
	while (first_pass || tmp != start)
	{
		first_pass = 0;
		if (in_range(tmp->value, max_range, range))
		{
			tmp = start->previous;
		}
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	wich_path(t_stacks *stacks, int max_range, int range, char c)
{
	int	path_start;
	int	path_end;

	path_start = path_to_start(stacks, max_range, range, c);
	path_end = path_to_end(stacks, max_range, range, c);
	if (path_start < path_end)
		return (1);
	return (0);
}

void	normal_move_path(t_stacks *stacks, t_tab *one_preset, int range)
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
}

int	get_pre_move_b(t_stacks *stacks, t_tab *one_preset, int range)
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
