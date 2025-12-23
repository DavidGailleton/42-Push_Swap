/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:18:06 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/09 10:17:27 by mteriier         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*previous;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;

typedef struct s_tab
{
	int				max_range;
	int				nb_in;
	struct s_tab	*next;
}	t_tab;

/*STACK_FUNCTIONS*/
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);
/*FUNCTION UTILS*/
t_stack		*new_stack(int value);
void		stack_add_back(t_stack **stack, t_stack *new);
void		stack_add_front(t_stack **stack, t_stack *new);
void		stack_clear_all(t_stack *stack, t_stack *first);
t_stack		*parsing(int argc, char **argv);
t_stacks	*init_big_stacks(int argc, char **argv);
int			ft_atoi(const char *nptr);
/*FUNCTION UTILS ALGO*/
int			check_order(t_stack *stack);
int			is_upper_compare(t_stack *t1, t_stack *t2);
int			stack_len(t_stack *stack);
/*FUNCTION FOR MEDIUM ALGO*/
t_tab		*get_tabs(t_stack *first, int range);
int			get_number_in_range(int max_range, t_stack *a, int range);
int			in_range(int value, int max_range, int range);
int			calcul_range(int value, int range);
int			get_next_lower(t_stack *first, int old_lower);
int			get_first_lower(t_stack *first);
int			my_sqrt(int nb);
int			get_max_number(t_stack *first);
int			get_min_number(t_stack *first);
int			range_bucket(t_stack *first);
t_tab		*free_tab(t_tab **first);
t_tab		*get_next_tab(t_stack *first, t_tab *tab, int range);
t_tab		*init_first_tab(t_stack *first, int range);
t_tab		*allocate_tab(int range_max, int nb);
int			wich_path(t_stacks *piles, int max_range, int range);
int			path_to_start(t_stacks *piles, int max_range, int range);
int			path_to_end(t_stacks *piles, int max_range, int range);
/*FUNCTION IN MAIN*/
void		print_all_stack(t_stack *stack, t_stack *first, char pile);
int			verif_no_double(int *tab, int len, int value);
int			adding_number(int *tab, int len);
int			*auto_shuffle(int len_tab);
/*FUNCTION IN FILE TEST*/
int			test1(int argc, char **argv);
int			test2(char **argv);
/*FUNCTION IN PARSIN 2*/
t_stack		*parsing2(int *tab, int len);
t_stacks	*init_big_stacks2(int *tab, int len);
void		print_tabs(t_tab *preset);

#endif
