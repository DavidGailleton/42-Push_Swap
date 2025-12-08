/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:21:05 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/08 16:50:25 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*parsing(int argc, char **argv)
{
	size_t	i;
	int		stock;
	t_stack	*first;
	t_stack	*new;

	i = 1;
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
}
