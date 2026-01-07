/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:18:06 by dgaillet          #+#    #+#             */
/*   Updated: 2026/01/07 10:30:42 by dgaillet         ###   ########lyon.fr   */
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

/* PRINT STACK FUNCTION*/
void	print_stacks(t_stacks *stacks, int len, t_stack *a, t_stack *b);
/*STACK_FUNCTIONS*/
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);
/* STACK ADD AND CLEAR FILES */
t_stack	*new_stack(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_clear_all(t_stack *stack, t_stack *first);
/* STACKS LEN FILES */
int		stack_a_len(t_stacks *stacks);
int		stack_b_len(t_stacks *stacks);
int		highest_stack_len(t_stacks *stacks);
/* PRE SORT */
int		r_to_lowest(t_stack *stack, int len);
void	sort_three_a(t_stacks *stacks);
/* ITERATE FILE */
void	optimal_rotate(t_stacks *stacks, int i, int len, char stack);
/* COMPARE FILE */
int		is_lowest(t_stack *stack, t_stack *node, int len);
int		is_highest(t_stack *stack, t_stack *node, int len);
/* CHECK ORDER FILE */
int		check_order(t_stack *stack);
/* INSERTION */
void	insertion(t_stacks *stacks, int len);
int		test2(char **argv);
/* TEST FILE */
int		test1(int argc, char **argv);

/* RADIX */
void	radix(t_stacks *stacks);

#endif
