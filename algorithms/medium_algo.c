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

int	path_to_end(t_stacks *piles, int max_range, int range)
{
	t_stack *tmp;
	int		i;
	int		first_pass;

	tmp = piles->a;
	tmp = tmp->previous;
	i = 0;
	first_pass = 1
	while (first_pass || tmp != piles->a->previous)
	{
		first_pass = 0;
		if (in_range(tmp->value, max_range, range))
			tmp = piles->a->previous;
		tmp = tmp->previous;
		i++;
	}
	return (i);
}

int	path_to_start(t_stacks *piles, int max_range, int range)
{
	t_stack *tmp;
	int		i;
	int		first_pass;

	tmp = piles ->a;
	i = 0;
	first_pass = 1;
	while (first_pass || tmp != piles->a)
	{
		first_pass = 0;
		if (in_range(tmp->value, max_range, range))
			tmp = piles->a;
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	wich_path(t_stacks *piles, int max_range, int range)
{
	int	path_start;
	int	path_end;

	path_start = path_to_start(piles, max_range, range);
	path_end = path_to_end(piles, max_range, range);
	if (path_start < path_end)
		return (1);
	return (0);
}

void	bucket_algo(void)
{
	return ;
}
