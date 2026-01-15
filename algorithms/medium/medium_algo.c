/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 07:14:45 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/06 12:57:05 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "medium_headers.h"
#include <stdlib.h>
#include <stdio.h>
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

int	stack_len(t_stack *stack)
{
	t_stack	*first;
	int		i;

	first = stack;
	i = 1;
	while (first->next != stack)
	{
		first = first->next;
		i++;
	}
	return (i);
}

void	bucket_algo(t_stacks *stacks, t_tab *preset, int range)
{
	t_tab	*tmp;

	tmp = preset;
	while(stacks->a)
		pb(stacks);
	//stacks->print = 0;
	while (preset)
	{
		push_range_to_b(stacks, preset, range);
		if (preset->next)
			tmp = preset->next;
		else
			tmp = NULL;
		if (preset)
			free(preset);
		preset = tmp;
	}
	return ;
}
