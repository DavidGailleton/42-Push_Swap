/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 14:30:38 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/09 12:05:56 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	secure_write(int fd, char *str, int len)
{
	if (len < 0)
		return ;
	if (write(fd, str, len) < 0)
		exit (EXIT_FAILURE);
}
