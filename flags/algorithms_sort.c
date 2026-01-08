/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:15:02 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/07 12:15:05 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "medium_algo.h"

void	simple(t_stacks *piles)
{
	int	len;

	len = stack_a_len(piles);
	piles->algo = 1;
	insertion(piles, len);
}

void	medium(t_stacks *piles)
{
	t_tab	*buckets;
	int		range;

	piles->algo = 2;
	range = range_bucket(piles->a);
	buckets = get_tabs(piles->a, range);
	bucket_algo(piles, buckets, range);
}

void	complex(t_stacks *piles)
{
	piles->algo = 3;
	radix(piles);
}

void	adaptive(t_stacks *piles)
{
	return ;
}
