/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:37:12 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/08 13:13:16 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

static int	check_flags(char *str)
{
	if (!ft_strncmp("--simple", str, ft_strlen(str)))
		return (1);
	else if (!ft_strncmp("--medium", argv[1], ft_strlen(argv[1])))
		return (1);
	else if (!ft_strncmp("--complex", argv[1], ft_strlen(argv[1])))
		return (1);
	else if (!ft_strncmp("--adaptative", argv[1], ft_strlen(argv[1])))
		return (1);
	return (0);
}

int	checker(int argc, char **argv)
{
	int	i;
	int	methods_flag;
	int	bench;

	bench = 0;
	methods_flag = 0;
	i = 0;
	while (++i < argc)
	{
		if (check_flags(argv[1]) && !methods_flag)
			methods_flag = 1;
		else if (!ft_strncmp("--bench", argv[1], ft_strlen(argv[1])) && !bench)
			bench = 1;
		else if (check_digits(argv[1]))
			continue ;
		else
			return (0);
	}
	return (1);
}
