/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:15:02 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 16:07:00 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "medium_headers.h"

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
	int		len;

	piles->algo = 2;
	len = stack_a_len(piles);
	if (len == 2)
		sort_two(piles);
	else
	{
		range = range_bucket(piles->a);
		buckets = get_tabs(piles->a, range);
		bucket_algo(piles, buckets, range);
	}
}

void	complex(t_stacks *piles)
{
	piles->algo = 3;
	radix(piles);
}

void	adaptive(t_stacks *piles)
{
	(void)piles;
	return ;
}
