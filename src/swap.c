/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:28 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/21 17:11:29 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_a(t_stack *stack_a)
{
	ft_putstr_fd("sa\n", 1);
	ft_swap(&stack_a->array[0], &stack_a->array[1]);
}

void	swap_b(t_stack *stack_b)
{
	ft_putstr_fd("sb\n", 1);
	ft_swap(&stack_b->array[0], &stack_b->array[1]);
}

void	sa_sb(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("ss\n", 1);
	swap_a(stack_a);
	swap_b(stack_b);
}

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
