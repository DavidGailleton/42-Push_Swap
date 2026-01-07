/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_headers.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mteriier <mteriier@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 07:47:49 by mteriier          #+#    #+#             */
/*   Updated: 2026/01/07 07:47:51 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEDIUM_HEADERS_H
# define MEDIUM_HEADERS_H

typedef struct s_tab
{
	int				max_range;
	int				nb_in;
	struct s_tab	*next;
}	t_tab;

/* MEDIUM ALGO FILE */
int		wich_path(t_stacks *piles, int max_range, int range, char c);
int		stack_len(t_stack *stack);
void	bucket_algo(t_stacks *piles, t_tab *preset, int range);
/* SORT UTILS 2 FILE */
void	sort_from_left(t_stacks *piles);
void	sort_from_right(t_stacks *piles);
/* SORT UTILS FILE */


#endif
