/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 01:01:26 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/23 01:01:26 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

#include <unistd.h>

int	has_dubble(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	parse_single_str(char *str, t_stack *stack_a)
{
	int		i;
	char	**splitted;

	i = 0;
	splitted = ft_split(str, 32);
	if (!splitted)
		ft_free_split(splitted);
	while (splitted[i])
	{
		if (ft_atoi(splitted[i]) == 2147483648
			|| (ft_atoi(splitted[i]) == 0 && splitted[i][0] != '0'))
		{
			ft_free_split(splitted);
			return (0);
		}
		stack_a->array[i] = ft_atoi(splitted[i]);
		i++;
		stack_a->size++;
	}
	ft_free_split(splitted);
	if (has_dubble(stack_a->array, stack_a->size))
		return (0);
	return (1);
}

int	get_rotations(t_stack *stack, int value)
{
	int	i;

	i = 0;
	while (stack->array[i] != value)
		i++;
	return (i);
}

int	get_min_cost(int rotations, int reverse_rotations)
{
	if (rotations <= reverse_rotations)
		return (rotations);
	else
		return (reverse_rotations);
}

void	get_best_push(t_stack *stack_a, t_stack *stack_b,
		int *best_value, int *best_target_value)
{
	int	i;
	int	push_cost;
	int	lower_push_cost;

	i = 0;
	*best_value = stack_a->array[i];
	*best_target_value = get_target_b_value(*best_value, stack_b);
	push_cost = get_push_cost(*best_value, *best_target_value,
			stack_a, stack_b);
	lower_push_cost = push_cost;
	while (i < stack_a->size)
	{
		push_cost = get_push_cost(stack_a->array[i],
				get_target_b_value(stack_a->array[i],
					stack_b), stack_a, stack_b);
		if (push_cost < lower_push_cost)
		{
			lower_push_cost = push_cost;
			*best_value = stack_a->array[i];
			*best_target_value = get_target_b_value(*best_value, stack_b);
		}
		i++;
	}
}
