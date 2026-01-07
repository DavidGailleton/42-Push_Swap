/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 08:03:08 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/07 08:03:10 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int			ft_atoi(const char *nptr);
t_stacks	*init_big_stacks2(int *tab, int len);
t_stacks	*init_big_stacks(int argc, char **argv);
int			ft_strncmp(const char *s1, const char *s2, int n);

#endif
