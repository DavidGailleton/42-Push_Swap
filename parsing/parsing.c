/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:21:05 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 14:01:23 by dgaillet         ###   ########lyon.fr   */
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
	char		**split_tab;
	int			i;

	i = 0;
	split_tab = ft_split(arv[wich_mod(mod)]);
	if (!split_tab)
		return (NULL);
	while ()
}

static void	set_t_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->algo = 0;
	stacks->bench = 0;
	stacks->disorder = 0;
	stacks->sa = 0;
	stacks->sb = 0;
	stacks->ss = 0;
	stacks->pa = 0;
	stacks->pb = 0;
	stacks->ra = 0;
	stacks->rb = 0;
	stacks->rr = 0;
	stacks->rra = 0;
	stacks->rrb = 0;
	stacks->rrr = 0;
}

t_stacks	*init_piles(int argc, char **argv, int mod)
{
	t_stacks	*stacks;
	t_stack		*a;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	set_t_stacks(stacks);
	a = parsing(argc, argv, mod);
	stacks->a = a;
	return (stacks);
}
