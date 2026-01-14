/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:46:41 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/13 13:42:37 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	size_t	i;
	char	*tmp;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len_s < start)
		len = 0;
	if (len > len_s - start)
		len = len_s - start;
	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	i = 0;
	while (i < len)
	{
		tmp[i] = s[start];
		i++;
		start++;
	}
	tmp[i] = '\0';
	return (tmp);
}
