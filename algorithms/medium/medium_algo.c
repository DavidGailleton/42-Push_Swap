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
	while (stacks->a)
		pb(stacks);
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
