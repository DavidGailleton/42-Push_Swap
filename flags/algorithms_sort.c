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
#include "parsing.h"

void	simple(t_stacks *stacks)
{
	int	len;

	len = stack_a_len(stacks);
	stacks->algo = 1;
	insertion(stacks, len);
}

void	medium(t_stacks *stacks)
{
	t_tab	*buckets;
	int		range;
	int		len;

	stacks->algo = 2;
	len = stack_a_len(stacks);
	if (len == 2)
		sort_two(stacks);
	else
	{
		range = range_bucket(stacks->a);
		buckets = get_tabs(stacks->a, range);
		if (!buckets)
			return ;
		bucket_algo(stacks, buckets, range);
	}
}

void	complex(t_stacks *stacks)
{
	stacks->algo = 3;
	radix(stacks);
}

void	adaptive(t_stacks *stacks, char **tab)
{
	int		i;
	float	disorder;

	i = 0;
	while (!ft_isdigit(tab[i][0]) && tab[i])
		i++;
	disorder = compute_disorder(tab, i - 1);
	if (disorder < 0.3)
		simple(stacks);
	else if (disorder < 0.46)
		medium(stacks);
	else
		complex(stacks);
	return ;
}
