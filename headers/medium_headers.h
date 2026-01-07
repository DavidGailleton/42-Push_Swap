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
/* SORT UTILS FILES */
void	sort_from_left(t_stacks *piles);
void	sort_from_right(t_stacks *piles);
void	push_range_to_b(t_stacks *piles, t_tab *one_preset, int range);
/* MEDIUM UTILS FILES */
int		range_bucket(t_stack *first);
int		get_first_lower(t_stack *first);
int		get_next_lower(t_stack *first, int old_lower);
int		calcul_range(int value, int range);
int		in_range(int value, int max_range, int range);
int		get_number_in_range(int max_range, t_stack *a, int range);
/* UTILS STRUCT TAB FILE */
t_tab	*get_tabs(t_stack *first, int range);

#endif
