/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:01:54 by mteriier          #+#    #+#             */
/*   Updated: 2025/11/12 08:34:59 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int	total_len;
	char	*tmp;

	total_len = ft_strlen(s1) + ft_strlen(s2);
	tmp = malloc((total_len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, s1, total_len + 1);
	ft_strlcat(tmp, s2, total_len + 1);
	return (tmp);
}
