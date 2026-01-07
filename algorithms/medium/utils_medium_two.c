/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_medium_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.lyon42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 09:36:56 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/22 09:38:19 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "medium_headers.h"

static int	get_max_number(t_stack *first)
{
	int		max;
	t_stack	*a;

	a = first;
	max = a->value;
	while (a->next != first)
	{
		if (max < a->value)
			max = a->value;
		a = a->next;
	}
	return (max);
}

static int	get_min_number(t_stack *first)
{
	int		min;
	t_stack	*a;

	a = first;
	min = a->value;
	while (a->next != first)
	{
		if (min > a->value)
			min = a->value;
		a = a->next;
	}
	return (min);
}

static int	my_sqrt(int nb)
{
	int	i;

	if (nb < 1)
		return (0);
	i = 0;
	while (i * i <= nb)
		i++;
	return (i);
}

int	range_bucket(t_stack *first)
{
	int	len;
	int	diff;
	int	sqrt;

	len = stack_len(first);
	diff = (get_max_number(first) - get_min_number(first)) ;
	sqrt = my_sqrt(len);
	if (diff / sqrt < 2)
	{
		return (get_max_number(first));
	}
	return ((get_max_number(first) - get_min_number(first)) / my_sqrt(len));
}
