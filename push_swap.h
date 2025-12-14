/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:18:06 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/12 14:06:25 by dgaillet         ###   ########lyon.fr   */
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
void		print_stacks(t_stacks *stacks, int len, t_stack *a, t_stack *b);
int			stack_a_len(t_stacks *stacks);
int			stack_b_len(t_stacks *stacks);
int			highest_stack_len(t_stacks *stacks);

/*ALGORITHM UTILS*/
int			check_order(t_stack *stack);
void		iterate_fn(t_stacks *stacks, int i, void (f)(t_stacks *stacks));
int			is_lowest(t_stack *stack, t_stack *node, int len);
int			is_highest(t_stack *stack, t_stack *node, int len);
void		optimal_rotate(t_stacks *stacks, int i, int len, char stack);

/*ALGORITHMS*/
void		bubble_alg(t_stacks *stacks);
//void		insertion(t_stacks *stacks, int a_len, int b_len);
void		insertion(t_stacks *stacks, int sorted, int len);

#endif
