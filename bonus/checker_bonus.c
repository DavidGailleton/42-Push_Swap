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
	if (ft_strncmp("sa\n", buf, ft_strlen(buf)))
		return (sa(stacks), 1);
	if (ft_strncmp("sb\n", buf, ft_strlen(buf)))
		return (sb(stacks), 1);
	if (ft_strncmp("ss\n", buf, ft_strlen(buf)))
		return (ss(stacks), 1);
	if (ft_strncmp("pa\n", buf, ft_strlen(buf)))
		return (pa(stacks), 1);
	if (ft_strncmp("pb\n", buf, ft_strlen(buf)))
		return (pb(stacks), 1);
	if (ft_strncmp("ra\n", buf, ft_strlen(buf)))
		return (ra(stacks), 1);
	if (ft_strncmp("rb\n", buf, ft_strlen(buf)))
		return (rb(stacks), 1);
	if (ft_strncmp("rr\n", buf, ft_strlen(buf)))
		return (rr(stacks), 1);
	if (ft_strncmp("rra\n", buf, ft_strlen(buf)))
		return (rra(stacks), 1);
	if (ft_strncmp("rrb\n", buf, ft_strlen(buf)))
		return (rrb(stacks), 1);
	if (ft_strncmp("rrr\n", buf, ft_strlen(buf)))
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
		return (secure_write(1, "KO\n", 3));
	if (!check_order(stacks->a))
		return (secure_write(1, "KO\n", 3));
	secure_write(1, "OK\n", 3);
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
		secure_write(2, "Error\n", 7);
	else
		bonus(tab);
	free_tab(tab);
	return (0);
}
