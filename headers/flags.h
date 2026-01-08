/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:05:52 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/07 13:05:53 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAGS_H
# define FLAGS_H

void	simple(t_stacks *piles);
void	medium(t_stacks *piles);
void	complex(t_stacks *piles);
void	adaptive(t_stacks *piles);
void	flags(int pos, int pos_b, char **argv, t_stacks *piles);
int		pos_bench(char **argv, int mod);
int		pos_flag(char **argv, int mod);
int		calcul_mod(int argc, char **argv);

#endif
