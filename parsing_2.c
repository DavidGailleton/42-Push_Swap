/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.lyon42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 13:10:58 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/22 13:11:21 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	print_tabs(t_tab *preset)
{
	t_tab	*tab;
	
	tab = preset;
	while (tab)
	{
		printf("MAX RANGE : [%d]\n", tab->max_range);
		printf("NUMBER IN : [%d]\n", tab->nb_in);
		tab = tab->next;
	}
}

t_stack	*parsing2(int *tab, int len)
{
	int		i;
	int		stock;
	t_stack	*first;
	t_stack	*new;

	i = 0;
	first = NULL;
	while (i < len)
	{
		stock = tab[i];
		new = new_stack(stock);
		if (!new && !first)
			return (NULL);
		else if (!new)
		{
			stack_clear_all(first, first);
			return (NULL);
		}
		stack_add_back(&first, new);
		i++;
	}
	return (first);
}

t_stacks	*init_big_stacks2(int *tab, int len)
{
	t_stacks	*stacks;
	t_stack		*a;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	a = parsing2(tab, len);
	stacks->a = a;
	return (stacks);
}
