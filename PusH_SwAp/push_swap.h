/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mustafa-machlouch <mustafa-machlouch@st    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 10:21:21 by mmachlou          #+#    #+#             */
/*   Updated: 2024/08/11 10:24:52 by mustafa-mac      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_stack
{
	int				data;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

int			main(int ac, char **av);
/*RULES*/
void		ft_sa(t_stack **stack_a);
void		ft_sb(t_stack **stack_b);
void		ft_ss(t_stack **stack_a, t_stack **stack_b);
void		ft_ra(t_stack **stack_a);
void		ft_rb(t_stack **stack_b);
void		ft_rr(t_stack **stack_a, t_stack **stack_b);
void		ft_rra(t_stack **stack_a);
void		ft_rrb(t_stack **stack_b);
void		ft_rrr(t_stack **stack_a, t_stack **stack_b);
void		ft_pa(t_stack **stack_a, t_stack **stack_b);
void		ft_pb(t_stack **stack_a, t_stack **stack_b);
/*COST*/
void		cost(t_stack **stack_a, t_stack **stack_b);
void		lowest_move(t_stack **stack_a, t_stack **stack_b);
void		ft_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
/*POSITION */
int			pos_of_lowest_index(t_stack **stack);
void		pos_of_target(t_stack **a, t_stack **b);
/*SORT */
int			is_sorted(t_stack *stack);
void		sort_three(t_stack **stack);
void		sort(t_stack **stack_a, t_stack **stack_b);
/*STACK*/
int			ft_stack_size(t_stack *stack);
t_stack		*new_stack(int data);
void		add_stack_bottom(t_stack **stack, t_stack *neww);
/*INITILAISITION*/
t_stack		*fill_stack_data(int ac, char **av);
void		assign_index(t_stack *stack_a, int stack_size);
/*INPUT CHECK */
int			is_input_correct(char **av);
int			is_digit(char c);
int			is_sign(char c);
int			nbstr_cmp(const char *s1, const char *s2);
/*ERROR */
void		free_stack(t_stack **stack);
void		error_exit(t_stack **stack_a, t_stack **stack_b);

#endif
