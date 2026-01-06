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
#include <stdlib.h>

int	path_to_end(t_stacks *piles, int max_range, int range, char c)
{
	t_stack	*tmp;
	int		i;
	int		first_pass;

	if (c == 'a')
		tmp = piles->a;
	else
		tmp = piles->b;
	tmp = tmp->previous;
	i = 0;
	first_pass = 1;
	while (first_pass || tmp != piles->b->previous)
	{
		first_pass = 0;
		if (in_range(tmp->value, max_range, range))
			tmp = piles->b;
		tmp = tmp->previous;
		i++;
	}
	return (i);
}

int	path_to_start(t_stacks *piles, int max_range, int range, char c)
{
	t_stack	*tmp;
	int		i;
	int		first_pass;

	if (c == 'a')
		tmp = piles->a;
	else
		tmp = piles->b;
	i = 0;
	first_pass = 1;
	while (first_pass || tmp != piles->b)
	{
		first_pass = 0;
		if (in_range(tmp->value, max_range, range))
		{
			tmp = piles->b->previous;
		}
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	wich_path(t_stacks *piles, int max_range, int range, char c)
{
	int	path_start;
	int	path_end;

	path_start = path_to_start(piles, max_range, range, c);
	path_end = path_to_end(piles, max_range, range, c);
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

void	bucket_algo(t_stacks *piles, t_tab *preset, int range)
{
	t_tab	*tmp;

	tmp = preset;
	while (piles->a)
		pb(piles);
	while (preset)
	{
		push_range_to_b(piles, preset, range);
		if (preset->next)
			tmp = preset->next;
		else
			tmp = NULL;
		if (preset)
			free(preset);
		preset = tmp;
	}
	while (piles->b)
		pa(piles);
	// print_all_stack(piles->a, piles->a, 'A');
	// print_all_stack(piles->b, piles->b, 'B');
	return ;
}
