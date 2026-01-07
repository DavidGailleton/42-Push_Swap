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
	if (mod == 0 || mod == 3)
		return (1);
	return (2);
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

static t_stack	*special_parsing(int argc, char **argv, int mod)
{
	t_stacks	*piles;
	t_stack		*first;
	t_stack		*new;
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
	a = parsing(argc, argv, mod);
	stacks->a = a;
	return (stacks);
}
