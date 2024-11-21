/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:22 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/21 17:11:23 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate_a(t_stack *stack_a)
{
	int	i;
	int	temp;

	if (stack_a->size < 2)
		return ;
	i = stack_a->size - 1;
	temp = stack_a->array[stack_a->size - 1];
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = temp;
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack *stack_b)
{
	int	i;
	int	temp;

	if (stack_b->size < 2)
		return ;
	i = stack_b->size - 1;
	temp = stack_b->array[stack_b->size - 1];
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->array[0] = temp;
	ft_putstr_fd("rrb\n", 1);
}

void	rra_rrb(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("rra\n", 1);
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
