/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 12:47:06 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/08 11:06:11 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	still_unit_index(t_stacks *stacks, int unit)
{
	t_stack	*temp;

	temp = stacks->a;
	if (!temp || temp->index >= unit)
		return (1);
	temp = temp->next;
	while (temp != stacks->a)
	{
		if (temp->index >= unit)
			return (1);
		temp = temp->next;
	}
	return (0);
}

static void	push_by_number_to_b(t_stacks *stacks, int unit, int nb)
{
	int		i;
	int		s_len;

	s_len = stack_a_len(stacks);
	i = 0;
	while (i < s_len && still_unit_index(stacks, unit))
	{
		if (stacks->a && (stacks->a->index % (unit * 10)) / unit == nb)
			pb(stacks);
		else
			ra(stacks);
		i++;
	}
}

static void	rec_sort(t_stacks *stacks, int unit)
{
	int	i;

	i = 0;
	if (!still_unit_index(stacks, unit))
		return ;
	while (i <= 9)
	{
		push_by_number_to_b(stacks, unit, i);
		i++;
	}
	while (stacks->b)
		pa(stacks);
	rec_sort(stacks, unit * 10);
}

void	radix(t_stacks *stacks)
{
	rec_sort(stacks, 1);
}
