/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:10:00 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/09 13:36:03 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stacks(t_stacks *stacks, int len, t_stack *a, t_stack *b)
{
	int		a_len;
	int		b_len;
	int		i;

	i = 0;
	a_len = stack_a_len(stacks);
	b_len = stack_b_len(stacks);
	while (i < len)
	{
		if (a_len >= len - i)
		{
			printf("%d", a->value);
			a = a->next;
		}
		printf("\t");
		if (b_len >= len - i)
		{
			printf("%d", b->value);
			b = b->next;
		}
		printf("\n");
		i++;
	}
	printf("_\t_\nA\tB\n\n");
}
