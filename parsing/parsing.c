/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:21:05 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/09 10:19:17 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include <stdlib.h>

static int	wich_mod(int mod)
{
	if (mod == 0)
		return (1);
	else if (mod == 1)
		return (2);
	else if (mod == 2)
		return (3);
	return (0);
}

static int	len_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

static t_stack	*parsing(int argc, char **argv, int mod)
{
	int		i;
	int		stock;
	t_stack	*first;
	t_stack	*new;

	i = wich_mod(mod);
	first = NULL;
	while (i < argc)
	{
		stock = ft_atoi(argv[i]);
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

static t_stack	*special_parsing(char **argv, int mod)
{
	t_stack		*a;
	char		**split_tab;
	int			len;
	int			i;

	i = mod % 3 + 1;
	split_tab = ft_split(argv[i], ' ');
	if (!split_tab)
		return (NULL);
	len = len_split(split_tab);
	a = parsing(len, split_tab, mod);
	free_tab(split_tab);
	return (a);
}

t_stacks	*init_piles(int argc, char **argv, int mod)
{
	t_stacks	*stacks;
	t_stack		*a;

	stacks = malloc(sizeof(t_stacks));
	stacks->a = NULL;
	stacks->b = NULL;
	if (!stacks)
		return (NULL);
	if (mod == 0 || mod == 1 || mod == 2)
		a = parsing(argc, argv, mod);
	else
		a = special_parsing(argv, mod);
	stacks->a = a;
	return (stacks);
}
