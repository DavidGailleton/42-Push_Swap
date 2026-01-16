/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:58:40 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/10 13:58:42 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_first_lower(t_stack *first)
{
	t_stack	*tmp;
	int		lower;
	int		pass;

	tmp = first;
	lower = tmp->index;
	pass = 1;
	while (tmp != first || pass == 1)
	{
		pass = 0;
		if (lower > tmp->index)
			lower = tmp->index;
		tmp = tmp->next;
	}
	return (lower);
}

int	get_next_lower(t_stack *first, int old_lower)
{
	t_stack	*tmp;
	int		next_lower;
	int		skip_first;

	tmp = first;
	skip_first = 1;
	next_lower = 2147483647;
	while (tmp != first || skip_first)
	{
		skip_first = 0;
		if (old_lower < tmp->index && tmp->index <= next_lower)
		{
			next_lower = tmp->index;
			if (next_lower == -2147483648)
				return (next_lower);
		}
		tmp = tmp->next;
	}
	return (next_lower);
}

int	calcul_range(int value, int range)
{
	int	max_range;

	max_range = 0;
	if (value == 2147483647)
		return (value);
	if (value < 0)
		while (max_range > value)
			max_range -= range;
	else
		while (max_range <= value)
			max_range += range;
	if (max_range < 0)
		return (max_range + range - 1);
	return (max_range - 1);
}

int	in_range(int value, int max_range, int range)
{
	int	min_range;

	min_range = max_range - (range - 1);
	if (value <= max_range && value >= min_range)
		return (1);
	return (0);
}

int	get_number_in_range(int max_range, t_stack *a, int range)
{
	int		nb_in;
	t_stack	*tmp;
	t_stack	*first;
	int		pass;

	nb_in = 0;
	tmp = a;
	pass = 1;
	first = tmp;
	while (tmp != first || pass == 1)
	{
		pass = 0;
		if (in_range(tmp->index, max_range, range))
			nb_in++;
		tmp = tmp->next;
	}
	return (nb_in);
}
