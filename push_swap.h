/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgaillet <dgaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:18:06 by dgaillet          #+#    #+#             */
/*   Updated: 2025/12/09 12:41:07 by mteriier         ###   ########lyon.fr   */
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

/*ALGORITHM UTILS*/
int	check_order(t_stack *stack);

/*ALGORITHMS*/
void	bubble_alg(t_stacks *stacks);

#endif
