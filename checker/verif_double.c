/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:41:42 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/09 10:41:43 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "check_error.h"

static int	is_double_in_tab(char **tab, int nb, int pos)
{
	int	i;

	i = pos;
	while (tab[i])
	{
		if (nb == ft_atoi(tab[i]))
			return (0);
		i++;
	}
	return (1);
}

int	verif_double(char **tab, int mod)
{
	int	i;
	int	tmp;

	i = wich_mod(mod);
	while (tab[i])
	{
		if (tab[i + 1])
		{
			tmp = ft_atoi(tab[i]);
			if (!is_double_in_tab(tab, tmp, i + 1))
				return (0);
		}
		i++;
	}
	return (1);
}
