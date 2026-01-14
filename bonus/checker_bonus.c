/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 11:46:36 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/09 14:51:32 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "get_next_line.h"
#include "check_error.h"
#include <unistd.h>

static int	apply_operation(t_stacks *stacks, char buf[1024])
{
	if (!ft_strncmp("sa", buf, ft_strlen(buf)))
		return (sa(stacks), 1);
	if (!ft_strncmp("sb", buf, ft_strlen(buf)))
		return (sb(stacks), 1);
	if (!ft_strncmp("ss", buf, ft_strlen(buf)))
		return (ss(stacks), 1);
	if (!ft_strncmp("pa", buf, ft_strlen(buf)))
		return (pa(stacks), 1);
	if (!ft_strncmp("pb", buf, ft_strlen(buf)))
		return (pb(stacks), 1);
	if (!ft_strncmp("ra", buf, ft_strlen(buf)))
		return (ra(stacks), 1);
	if (!ft_strncmp("rb", buf, ft_strlen(buf)))
		return (rb(stacks), 1);
	if (!ft_strncmp("rr", buf, ft_strlen(buf)))
		return (rr(stacks), 1);
	if (!ft_strncmp("rra", buf, ft_strlen(buf)))
		return (rra(stacks), 1);
	if (!ft_strncmp("rrb", buf, ft_strlen(buf)))
		return (rrb(stacks), 1);
	if (!ft_strncmp("rrr", buf, ft_strlen(buf)))
		return (rrr(stacks), 1);
	return (0);
}

static int	is_stacks_b_empty(t_stacks *stacks)
{
	if (stacks->b != NULL)
		return (0);
	return (1);
}

static int	tester(t_stacks *stacks)
{
	char	*buf;

	buf = get_next_line(0);
	while (buf)
	{
		if (!apply_operation(stacks, buf))
			break ;
		free(buf);
		buf = get_next_line(0);
	}
	if (!is_stacks_b_empty(stacks))
		return (write(1, "KO\n", 3));
	if (!check_order(stacks->a))
		return (write(1, "KO\n", 3));
	write(1, "OK\n", 3);
	return (0);
}

static int	bonus(char **tab)
{
	t_stacks	*stacks;
	int			len;

	stacks = NULL;
	len = len_split(tab);
	stacks = init_stacks(len, tab, 0);
	stacks->print = 0;
	if (!stacks)
		return (0);
	tester(stacks);
	free_all(stacks);
	return (1);
}

int	main(int argc, char **argv)
{
	char		**tab;

	if (argc < 2)
		return (write(2, "Error\n", 7));
	tab = split_all(join_all(argc, argv));
	if (!tab)
		return (0);
	if (!check_error_bonus(tab))
		write(2, "Error\n", 7);
	else
		bonus(tab);
	free_tab(tab);
	return (0);
}
