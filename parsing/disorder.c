/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:05:37 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/09 11:26:24 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	strs_len(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

float	compute_disorder(char **strs)
{
	float	mistakes;
	float	total_pairs;
	int		i;
	int		j;

	mistakes = 0;
	total_pairs = 0;
	i = 0;
	while (i < strs_len(strs))
	{
		j = i + 1;
		while (j < strs_len(strs))
		{
			total_pairs += 1;
			if (strs[i] > strs[j])
				mistakes += 1;
		}
	}
	return (mistakes / total_pairs);
}
