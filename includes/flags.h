/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:05:52 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/08 15:32:54 by dgaillet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

void	simple(t_stacks *stacks);
void	medium(t_stacks *stacks);
void	complex(t_stacks *stacks);
void	adaptive(t_stacks *stacks, char **tab);
void	flags(int pos, int pos_b, char **argv, t_stacks *stacks);
int		pos_bench(char **argv, int mod);
int		pos_flag(char **argv, int mod);
int		calcul_mod(int argc, char **argv);
void	print_bench(t_stacks *stacks);

#endif
