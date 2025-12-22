/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct_tab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:36:43 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/10 13:36:48 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_tab	*allocate_tab(int range_max, int nb)
{
	t_tab	*tab;

	tab = malloc(sizeof(t_tab));
	if (!tab)
		return (NULL);
	tab->max_range = range_max;
	tab->nb_in = nb;
	return (tab);
}

t_tab	*get_tabs(t_stack *first, int range)
{
	t_tab	*tmp;
	t_tab	*first_tab;
	int		len_stack;
	int		scan_nb_in_tab;

	len_stack = stack_len(first);
	first_tab = init_first_tab(first, range);
	if (!first_tab)
		return (NULL);
	scan_nb_in_tab = first_tab->nb_in;
	tmp = first_tab;
	while (scan_nb_in_tab < len_stack)
	{
		tmp->next = get_next_tab(first, tmp, range);
		if (!(tmp->next))
			return (free_tab(first_tab));
		tmp = tmp->next;
		scan_nb_in_tab += tmp->nb_in;
	}
	return (first_tab);
}

t_tab	*init_first_tab(t_stack *first, int range)
{
	t_tab	*tab;
	int		lower;
	int		range_max;

	lower = get_first_lower(first);
	range_max = calcul_range(lower, range);
	tab = allocate_tab(range_max, get_number_in_range(range_max, first, range));
	if (!tab)
		return (NULL);
	return (tab);
}

t_tab	*get_next_tab(t_stack *first, t_tab *tab, int range)
{
	int		lower;
	int		range_max;
	t_tab	*next_tab;

	lower = get_next_lower(first, tab->max_range);
	range_max = calcul_range(lower, range);
	next_tab = allocate_tab(range_max,
			get_number_in_range(range_max, first, range));
	return (next_tab);
}

t_tab	*free_tab(t_tab *first)
{
	t_tab	*tmp;

	while (first)
	{
		tmp = first->next;
		free(first);
		first = tmp;
	}
	return (NULL);
}
