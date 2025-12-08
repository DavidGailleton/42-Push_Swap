/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 18:28:17 by mteriier          #+#    #+#             */
/*   Updated: 2025/12/08 18:30:28 by mteriier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	size_t	i;
	int		sign;
	int		tmp;

	i = 0;
	sign = 1;
	tmp = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	sign = calcul_sign(nptr[i]);
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		tmp = tmp * 10 + nptr[i] - '0';
		i++;
	}
	return (tmp * sign);
}
