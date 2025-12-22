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

	tmp = first;
	lower = tmp->value;
	while (tmp->next != first)
	{
		if (lower < tmp->value)
			lower = tmp->value;
		tmp = tmp->next;
	}
	return (lower);
}

int	get_next_lower(t_stack *first, int old_lower)
{
	t_stack	*tmp;
	int		next_lower;

	tmp = first;
	next_lower = tmp->value;
	while (tmp->next != first)
	{
		if (tmp->value != old_lower && next_lower < tmp->value)
			next_lower = tmp->value;
		tmp = tmp->next;
	}
	return (next_lower);
}

int	calcul_range(int value, int range)
{
	int	max_range;

	max_range = 0;
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

	nb_in = 0;
	tmp = a;
	first = tmp;
	while (tmp->next != first)
	{
		if (in_range(tmp->value, max_range, range))
			nb_in++;
		tmp = tmp->next;
	}
	return (nb_in);
}
