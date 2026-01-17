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

int	wich_mod(int mod)
{
	return (mod % 3 + 1);
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

static void	set_t_stacks(t_stacks *stacks)
{
	stacks->a = NULL;
	stacks->b = NULL;
	stacks->algo = 0;
	stacks->bench = 0;
	stacks->disorder = 0;
	stacks->print = 1;
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

static void	set_flags(int argc, char **argv, t_stacks *stacks)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strncmp(argv[i], "--simple", ft_strlen(argv[i])))
			stacks->algo = 1;
		else if (ft_strncmp(argv[i], "--medium", ft_strlen(argv[i])))
			stacks->algo = 2;
		else if (ft_strncmp(argv[i], "--complex", ft_strlen(argv[i])))
			stacks->algo = 3;
		if (ft_strncmp(argv[i], "--bench", ft_strlen(argv[i])))
			stacks->bench = 1;
		i++;
	}
}

t_stacks	*init_stacks(int argc, char **argv, int mod)
{
	t_stacks	*stacks;
	t_stack		*a;

	stacks = malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	set_t_stacks(stacks);
	a = parsing(argc, argv, mod);
	if (!a)
	{
		free(stacks);
		return (NULL);
	}
	stacks->a = a;
	set_flags(argc, argv, stacks);
	stacks->disorder = compute_disorder(argv, wich_mod(mod));
	return (stacks);
}
