/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 08:03:08 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 14:15:37 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <stdlib.h>
# include "push_swap.h"

int			ft_atoi(const char *nptr);
t_stacks	*init_stacks(int argc, char **argv, int mod);
int			ft_strncmp(const char *s1, const char *s2, int n);
size_t		ft_strlen(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
void		free_tab(char **tab);
int			checker(int argc, char **argv);
int			len_split(char **tab);
char		*ft_itoa(int n);
int			ft_isdigit(int c);
char		*ft_strjoin(char const *s1, char const *s2);
int			ft_strlcpy(char *dst, const char *src, int size);
int			ft_strlcat(char *dst, const char *src, int size);
char		*join_all(int argc, char **argv);
char		**split_all(char *tab);

#endif
