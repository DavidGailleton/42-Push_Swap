/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:32:35 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 15:34:59 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include "check_error.h"
#include "flags.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	char	**tab;
	int		mod;
	int		len;

	if (argc < 2)
		return (0);
	tab = split_all(join_all(argc, argv));
	if (!tab)
		return (0);
	len = len_split(tab);
	mod = calcul_mod(len, tab);
	if (check_error(tab, mod))
		test1(tab, len, mod);
	else
		write(2, "Error\n", 6);
	free_tab(tab);
	return (0);
}
