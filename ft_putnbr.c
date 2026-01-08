/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:17:28 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/08 15:19:30 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	char	c;

	if (!nbr)
		return ;
	ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	secure_write(fd, &c, 1);
}
