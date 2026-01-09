/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:17:28 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/09 12:09:55 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rec_ft_putnbr_fd(int nbr, int fd)
{
	char	c;

	if (!nbr)
		return ;
	ft_putnbr_fd(nbr / 10, fd);
	c = (nbr % 10) + '0';
	secure_write(fd, &c, 1);
}

void	ft_putnbr_fd(int nbr, int fd)
{
	if (!nbr)
		secure_write(fd, "0", 1);
	rec_ft_putnbr_fd(nbr, fd);
}
