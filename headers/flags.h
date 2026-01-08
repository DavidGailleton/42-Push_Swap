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

void	simple(t_stacks *piles);
void	medium(t_stacks *piles);
void	complex(t_stacks *piles);
void	adaptive(t_stacks *piles);
void	flags(int pos, char **argv, t_stacks *piles);

void	print_bench(t_stacks *stacks);

#endif
