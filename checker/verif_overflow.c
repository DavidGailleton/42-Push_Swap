/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_overflow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:30:39 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/09 10:30:40 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

// static int	calcul_sign(char c)
// {
// 	if (c == '-')
// 		return (-1);
// 	return (1);
// }

static int	verif_atoi(const char *nptr)
{
	size_t	i;
	int		tmp;
	int		before;

	i = 0;
	tmp = 0;
	before = 0;
	if (ft_strncmp(nptr, "-2147483648", 15))
		return (1);
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		before = tmp;
		tmp = tmp * 10 + nptr[i] - '0';
		if (before > tmp)
			return (0);
		i++;
	}
	return (1);
}

int	verif_overflow(char **tab, int mod)
{
	int	i;

	i = wich_mod(mod);
	while (tab[i])
	{
		if (!verif_atoi(tab[i]))
			return (0);
		i++;
	}
	return (1);
}
