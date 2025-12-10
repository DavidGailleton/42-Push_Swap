/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 07:14:45 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/10 07:14:51 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_tab	*get_tabs(t_stack *first)
{
	t_tab	*tmp;
	t_tab	*first_tab;
	int		len_stack;
	int		scan_nb_in_tab;

	len_stack = stack_len(first);
	first_tab = first_tab(first);
	if (!first_tab)
		return (NULL);
	scan_nb_in_tab = tab->nb_in;
	tmp = first_tab;
	while (scan_nb_in_tab < len_stack)
	{
		tmp->next = get_next_tab(first, tmp);
		if (!(tmp->next))
			return (free_tab(first_tab));
		tmp = tmp->next;
		scan_nb_in_tab += tmp->nb_in;
	}
	return (first_tab);
}
