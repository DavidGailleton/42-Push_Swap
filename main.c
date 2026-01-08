/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:32:35 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 12:57:04 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "parsing.h"
#include <unistd.h>

int	main(int argc, char **argv)
{
	if (!checker(argc, argv))
	{
		write(2, "Error !\n", 8);
		return (1);
	}

	if (argc > 1)
		test1(argc, argv);
	return (0);
}
