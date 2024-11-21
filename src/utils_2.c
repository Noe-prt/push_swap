/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:34 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/21 17:19:38 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_target_b_value(int value, t_stack *stack_b)
{
	int	closest_smaller;
	int	max_value;
	int	current;
	int	i;

	if (!stack_b || stack_b->size <= 0)
		return (0);
	closest_smaller = INT_MIN;
	max_value = INT_MIN;
	i = 0;
	current = stack_b->array[0];
	while (i < stack_b->size)
	{
		current = stack_b->array[i];
		if (current > max_value)
			max_value = current;
		if (current < value && current > closest_smaller)
			closest_smaller = current;
		i++;
	}
	if (closest_smaller == INT_MIN)
		return (max_value);
	return (closest_smaller);
}

int	get_target_a_value(int value, t_stack *stack_a)
{
	int	closest_greater;
	int	min_value;
	int	current;
	int	i;

	if (!stack_a || stack_a->size <= 0)
		return (0);
	closest_greater = INT_MAX;
	min_value = INT_MAX;
	i = 0;
	while (i < stack_a->size)
	{
		current = stack_a->array[i];
		if (current < min_value)
			min_value = current;
		if (current > value && current < closest_greater)
			closest_greater = current;
		i++;
	}
	if (closest_greater == INT_MAX)
		return (min_value);
	return (closest_greater);
}

int	get_push_cost(int value, int target_value, t_stack *stack_a,
					t_stack *stack_b) // REDUIRE !!!!
{
	int	cost;
	int	i;
	int	rotations_a
	int	reverse_rotations_a;
	int	rotations_b
	int	reverse_rotations_b;

	cost = 0;
	i = 0;
	while (stack_a->array[i] != value)
		i++;
	rotations_a = i;
	reverse_rotations_a = stack_a->size - i;
	i = 0;
	while (stack_b->array[i] != target_value)
		i++;
	rotations_b = i;
	reverse_rotations_b = stack_b->size - i;
	if (rotations_a <= reverse_rotations_a)
		cost += rotations_a;
	else
		cost += reverse_rotations_a;
	if (rotations_b <= reverse_rotations_b)
		cost += rotations_b;
	else
		cost += reverse_rotations_b;
	return (cost);
}

void	rotate_stacks_to_top(int value, int target_value, t_stack *stack_a,
		t_stack *stack_b)
{
	int	index_a;
	int	index_b;

	index_a = 0;
	index_b = 0;
	while (stack_a->array[index_a] != value)
		index_a++;
	while (stack_b->array[index_b] != target_value)
		index_b++;
	if (index_a < stack_a->size / 2)
		while (stack_a->array[0] != value)
			rotate_a(stack_a);
	else
		while (stack_a->array[0] != value)
			reverse_rotate_a(stack_a);
	if (index_b < stack_b->size / 2)
		while (stack_b->array[0] != target_value)
			rotate_b(stack_b);
	else
		while (stack_b->array[0] != target_value)
			reverse_rotate_b(stack_b);
}

void	move_min_value_on_top(t_stack *stack_a)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min_index = 0;
	min = stack_a->array[0];
	while (i < stack_a->size)
	{
		if (min > stack_a->array[i])
		{
			min = stack_a->array[i];
			min_index = i;
		}
		i++;
	}
	if (min_index < stack_a->size / 2)
		while (stack_a->array[0] != min)
			rotate_a(stack_a);
	else
		while (stack_a->array[0] != min)
			reverse_rotate_a(stack_a);
}
