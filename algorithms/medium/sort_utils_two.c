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

int	get_value_finded(t_stacks *stacks, t_tab *one_preset, int range)
{
	int		value;
	t_stack	*tmp;

	tmp = assign_stack(stacks, 'b');
	if (wich_path(stacks, one_preset->max_range, range, 'b'))
	{
		while (!in_range(tmp->index, one_preset->max_range, range))
			tmp = tmp->next;
	}
	else
		while (!in_range(tmp->index, one_preset->max_range, range))
			tmp = tmp->previous;
	value = tmp->index;
	return (value);
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
