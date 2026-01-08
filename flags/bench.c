/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:59:52 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/08 16:09:11 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include <unistd.h>
#include <stdlib.h>

static void	print_disorder(t_stacks *stacks)
{
	int		nbr;
	char	*str;

	nbr = (int) stacks->disorder * 10000;
	str = ft_itoa(nbr);
	if (!str)
		exit ( EXIT_FAILURE );
	secure_write(2, "[bench] disorder: ", 18);
	if (ft_strlen(str) == 2)
		secure_write(2, "0", 1);
	else
		secure_write(2, str, ft_strlen(str) - 2);
	secure_write(2, ".", 1);
	secure_write(2, &str[ft_strlen(str) - 2], 2);
	secure_write(2, "%\n", 2);
	free(str);
}

static void	print_algo(t_stacks *stacks)
{
	secure_write(2, "[bench] algo: ", 18);
	if (stacks->algo == 0)
	{
		secure_write(2, "Adaptative", 10);
		if (stacks->disorder < 0.2)
			secure_write(2, " / O(n2n)\n", 10);
		else if (stacks->disorder >= 0.5)
			secure_write(2, " / O(n√n)\n", 10);
		else
			secure_write(2, " / O(nlogn)\n", 12);
	}
	else if (stacks->algo == 1)
		secure_write(2, "Simple / O(n2n)\n", 16);
	else if (stacks->algo == 2)
		secure_write(2, "Medium / O(nlogn)\n", 18);
	else if (stacks->algo == 3)
		secure_write(2, "Complex / O(n√n)\n", 17);
}

static void	print_total_ops(t_stacks *stacks)
{
	unsigned int	total_ops;

	total_ops = 0;
	total_ops += stacks->sa;
	total_ops += stacks->sb;
	total_ops += stacks->ss;
	total_ops += stacks->pa;
	total_ops += stacks->pb;
	total_ops += stacks->ra;
	total_ops += stacks->rb;
	total_ops += stacks->rr;
	total_ops += stacks->rra;
	total_ops += stacks->rrb;
	total_ops += stacks->rrr;
	secure_write(2, "[bench] total_ops: ", 18);
	ft_putnbr_fd((int) total_ops, 2);
	secure_write(2, "\n", 1);
}

static void	print_ops(t_stacks *stacks)
{
	secure_write(2, "[bench] sa: ", 11);
	ft_putnbr_fd((int) stacks->sa, 2);
	secure_write(2, " sb: ", 5);
	ft_putnbr_fd((int) stacks->sb, 2);
	secure_write(2, " ss: ", 5);
	ft_putnbr_fd((int) stacks->ss, 2);
	secure_write(2, " pa: ", 5);
	ft_putnbr_fd((int) stacks->pa, 2);
	secure_write(2, " pb: ", 5);
	ft_putnbr_fd((int) stacks->pb, 2);
	secure_write(2, "\n", 1);
	secure_write(2, "[bench] ra: ", 5);
	ft_putnbr_fd((int) stacks->ra, 2);
	secure_write(2, " rb: ", 5);
	ft_putnbr_fd((int) stacks->rb, 2);
	secure_write(2, " rr: ", 5);
	ft_putnbr_fd((int) stacks->rr, 2);
	secure_write(2, " rra: ", 6);
	ft_putnbr_fd((int) stacks->rra, 2);
	secure_write(2, " rrb: ", 6);
	ft_putnbr_fd((int) stacks->rrb, 2);
	secure_write(2, " rrr: ", 6);
	ft_putnbr_fd((int) stacks->rrr, 2);
	secure_write(2, "\n", 1);
}

void	print_bench(t_stacks *stacks)
{
	print_disorder(stacks);
	print_algo(stacks);
	print_total_ops(stacks);
	print_ops(stacks);
}
