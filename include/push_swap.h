/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:38 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/22 10:27:14 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../Libft/libft.h"
# include <limits.h>
# include <stdlib.h>
#include <stdio.h>

typedef struct s_stack
{
	int	*array;
	int	size;
	int	capacity;
}		t_stack;

void	push_swap(t_stack *stack_a, t_stack *stack_b);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
void	swap_a(t_stack *stack_a);
void	swap_b(t_stack *stack_b);
void	sa_sb(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack_a);
void	rotate_b(t_stack *stack_b);
void	ra_rb(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_a(t_stack *stack_a);
void	reverse_rotate_b(t_stack *stack_b);
void	rra_rrb(t_stack *stack_a, t_stack *stack_b);
void	ft_swap(int *a, int *b);
t_stack	*init_stack(int capacity, char **argv);
void	free_stack(t_stack *stack);
int		parse_args(int argc, char **argv, t_stack *stack_a);
int		get_target_b_value(int value, t_stack *stack_b);
int		get_target_a_value(int value, t_stack *stack_a);
int		get_push_cost(int value, int target_value, t_stack *stack_a,
			t_stack *stack_b);
void	rotate_stacks_to_top(int value, int target_value, t_stack *stack_a,
			t_stack *stack_b);
void	move_min_value_on_top(t_stack *stack_a);
void	sort_three(t_stack *stack_a);
void	sort_simples_cases(t_stack *stack_a);
void	push_numbers_to_b(t_stack *stack_a, t_stack *stack_b);
void	push_numbers_to_a(t_stack *stack_a, t_stack *stack_b);

#endif
