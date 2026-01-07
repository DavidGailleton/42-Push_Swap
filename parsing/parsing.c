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

static t_stack	*parsing(int argc, char **argv)
{
	int		i;
	int		stock;
	t_stack	*first;
	t_stack	*new;

	i = 1;
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

t_stacks	*init_big_stacks(int argc, char **argv)
{
	t_stacks	*stacks;
	t_stack		*a;

	stacks = malloc(sizeof(t_stacks));
	stacks->a = NULL;
	stacks->b = NULL;
	if (!stacks)
		return (NULL);
	a = parsing(argc, argv);
	stacks->a = a;
	return (stacks);
}
