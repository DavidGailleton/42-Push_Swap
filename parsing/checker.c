/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 12:37:12 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/08 12:54:19 by dgaillet         ###   ########lyon.fr   */
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

int	checker(int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
	{
		if (ft_strncmp("--simple", argv[1], ft_strlen(argv[1])))
			continue ;
		if (ft_strncmp("--medium", argv[1], ft_strlen(argv[1])))
			continue ;
		if (ft_strncmp("--complex", argv[1], ft_strlen(argv[1])))
			continue ;
		if (ft_strncmp("--adaptative", argv[1], ft_strlen(argv[1])))
			continue ;
		if (check_digits(argv[1]))
			continue ;
		else
			return (0);
	}
	return (1);
}
