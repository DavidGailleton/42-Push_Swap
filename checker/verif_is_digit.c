/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_is_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:25:23 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/09 10:25:24 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static int	scan_str_is_digit(char *tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!ft_isdigit(tab[i]) && (tab[i] == '-' && !ft_isdigit(tab[i + 1])))
			return (0);
		if (tab[i] == '+' && !ft_isdigit(tab[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int	verif_is_digit(char **tab, int mod)
{
	int	i;

	i = wich_mod(mod);
	while (tab[i])
	{
		if (!scan_str_is_digit(tab[i]))
			return (0);
		i++;
	}
	return (1);
}
