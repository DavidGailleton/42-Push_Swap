/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 09:31:50 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/09 09:31:51 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "check_error.h"
#include "parsing.h"

int	verif_is_number(char **tab)
{
	int	len;

	len = len_split(tab);
	if (tab[len - 1][0] == '-' && !ft_isdigit(tab[len - 1][1]))
		return (0);
	return (1);
}

int	check_error_bonus(char **tab)
{
	if (!verif_is_digit(tab, 0))
		return (0);
	if (!verif_overflow(tab, 0))
		return (0);
	if (!verif_double(tab, 0))
		return (0);
	return (1);
}

int	check_error(char **tab, int mod)
{
	if (!verif_flag(tab, mod))
		return (0);
	if (!verif_is_digit(tab, mod))
		return (0);
	if (!verif_overflow(tab, mod))
		return (0);
	if (!verif_double(tab, mod))
		return (0);
	if (!verif_is_number(tab))
		return (0);
	return (1);
}
