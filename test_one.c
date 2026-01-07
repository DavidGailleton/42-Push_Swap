/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.lyon42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:33:58 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/07 14:58:10 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "medium_headers.h"
#include <stdio.h>
#include <stdlib.h>

int	test1(int argc, char **argv)
{
	t_stacks	*piles;
	//t_tab		*preset;

	piles = NULL;
	if (argc > 1)
	{
		piles = init_big_stacks(argc, argv);
		//preset = get_tabs(piles->a, range_bucket(piles->a));
		//bucket_algo(piles, preset, range_bucket(piles->a));
		radix(piles);
	}
	free_all(piles);
	//free(piles);
	return (0);
}
