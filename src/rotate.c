/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:25 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/21 17:11:26 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_a(t_stack *stack_a)
{
	int	i;
	int	temp;

	ft_putstr_fd("ra\n", 1);
	if (stack_a->size <= 1)
		return ;
	i = 0;
	temp = stack_a->array[0];
	while (i < stack_a->size - 1)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
	stack_a->array[stack_a->size - 1] = temp;
}

void	rotate_b(t_stack *stack_b)
{
	int	i;
	int	temp;

	ft_putstr_fd("rb\n", 1);
	if (stack_b->size <= 1)
		return ;
	i = 0;
	temp = stack_b->array[0];
	while (i < stack_b->size - 1)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
	stack_b->array[stack_b->size - 1] = temp;
}

void	ra_rb(t_stack *stack_a, t_stack *stack_b)
{
	ft_putstr_fd("rr\n", 1);
	rotate_a(stack_a);
	rotate_b(stack_b);
}
