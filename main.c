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
#include <string.h>

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

int	adding_number(int *tab, int len)
{
	int	stock;

	stock = tab[0];
	while (!verif_no_double(tab, len, stock))
	{
		stock = 0 + rand() % (250 - 0 + 1);
	}
	return (stock);
}

int	*auto_shuffle(int len_tab)
{
	int	*tab;
	int	i;

	i = 1;
	tab = malloc(len_tab * sizeof(int));
	if (!tab)
		return (NULL);
	tab[0] = 0 + rand() % (250 - 0 + 1);
	while (i < len_tab)
	{
		tab[i] = adding_number(tab, i - 1);
		i++;
	}
	return (tab);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "-t2") == 0)
			test2(argv++);
		else
			test1(argc, argv);
	}
	return (0);
}
