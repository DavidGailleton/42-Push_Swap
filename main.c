/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:32:35 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/09 11:39:55 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	print_all_stack(t_stack *stack, t_stack *first, char pile)
{
	t_stack	*tmp;
	int		i;

	tmp = stack;
	i = 0;
	printf("TAB %c : \n", pile);
	if (!stack || !first)
		return ;
	while (tmp->next != first)
	{
		printf("[%d] ", tmp->value);
		tmp = tmp->next;
		i++;
	}
	printf("[%d] \n", tmp->value);
}

int	verif_no_double(int *tab, int len, int value)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (value == tab[i])
			return (0);
		i++;
	}
	return (1);
}

int adding_number(int *tab, int len)
{
	int stock;

	stock = tab[0];
	while (!verif_no_double(tab, len, stock))
	{
		stock = rand();
	}
	return stock;
}

int	*auto_shuffle(int len_tab)
{
	int	*tab;
	int	i;
	int	len_added;

	i = 1;
	tab = malloc(len_tab * sizeof(int));
	if (!tab)
		return (NULL);
	tab[0] = rand();
	while (i < len_tab)
	{
		tab[i] = adding_number(tab, i);
		i++;
	}
	return (tab);
}


int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = NULL;
	if (argc > 1)
	{
		stacks = init_big_stacks(argc, argv);
		print_all_stack(stacks->a, stacks->a, 'A');
		print_all_stack(stacks->b, stacks->b, 'B');
		rra(stacks);
		print_all_stack(stacks->a, stacks->a, 'A');
		print_all_stack(stacks->b, stacks->b, 'B');
	}
	if (stacks->a)
		stack_clear_all(stacks->a, stacks->a);
	if (stacks->b)
		stack_clear_all(stacks->b, stacks->b);
}
