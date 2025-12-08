/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:32:35 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/08 20:36:49 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_all_stack(t_stack *stack, t_stack *first)
{
	t_stack	*tmp;

	tmp = stack;
	printf("TAB\n");
	while (tmp->next != first)
	{
		printf("[%d] ", tmp->value);
		tmp = tmp->next;
	}
	printf("[%d] \n", tmp->value);
}

int	main(int argc, char **argv)
{
	t_stack	*first;

	if (argc > 1)
	{
		first = parsing(argc, argv);
		print_all_stack(first, first);
	}
	stack_clear_all(first, first);
}
