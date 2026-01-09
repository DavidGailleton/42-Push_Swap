/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 09:22:05 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/13 11:03:31 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	ft_strlcat(char *dst, const char *src, int size)
{
	int	i;
	int	j;
	int	len_src;
	int	len_dst;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	j = ft_strlen(dst);
	len_dst = ft_strlen(dst);
	while (j < size - 1 && src[i])
	{
		dst[j] = src[i];
		j++;
		i++;
	}
	dst[j] = '\0';
	if (len_dst > size)
		return (len_src + size);
	return (len_dst + len_src);
}
