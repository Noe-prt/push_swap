/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:12 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/21 17:13:38 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (0);
	stack_a = init_stack(argc - 1);
	stack_b = init_stack(argc - 1);
	if (!stack_a || !stack_b || !parse_args(argc, argv, stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (1);
	}
	push_swap(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}

void	push_swap(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size <= 3)
	{
		sort_simples_cases(stack_a);
		return ;
	}
	push_b(stack_a, stack_b);
	push_b(stack_a, stack_b);
	while (stack_a->size > 3)
	{
		push_numbers_to_b(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
	{
		push_numbers_to_a(stack_a, stack_b);
	}
	move_min_value_on_top(stack_a);
}

void	push_numbers_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	lower_push_cost;
	int	value;
	int	target_value;
	int	push_cost;

	i = 0;
	value = stack_a->array[i];
	target_value = get_target_b_value(value, stack_b);
	push_cost = get_push_cost(value, target_value, stack_a, stack_b);
	lower_push_cost = push_cost;
	while (i < stack_a->size)
	{
		if (get_push_cost(stack_a->array[i],
				get_target_b_value(stack_a->array[i], stack_b), stack_a,
				stack_b) < lower_push_cost)
		{
			lower_push_cost = get_push_cost(stack_a->array[i],
					get_target_b_value(stack_a->array[i], stack_b), stack_a,
					stack_b);
			value = stack_a->array[i];
			target_value = get_target_b_value(stack_a->array[i], stack_b);
		}
		i++;
	}
	rotate_stacks_to_top(value, target_value, stack_a, stack_b);
	push_b(stack_a, stack_b);
}

void	push_numbers_to_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	value;
	int	target_value;

	i = 0;
	value = stack_b->array[i];
	target_value = get_target_a_value(value, stack_a);
	while (stack_a->array[i] != target_value)
		i++;
	if (i < stack_a->size / 2)
		while (stack_a->array[0] != target_value)
			rotate_a(stack_a);
	else
		while (stack_a->array[0] != target_value)
			reverse_rotate_a(stack_a);
	push_a(stack_a, stack_b);
}
