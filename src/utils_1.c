/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nopareti <nopareti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:11:31 by nopareti          #+#    #+#             */
/*   Updated: 2024/11/22 10:34:58 by nopareti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*init_stack(int capacity, char **argv)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	if (capacity == 1)
		stack->array = malloc(sizeof(int) * ft_count_words(argv[1], 32));
	else
		stack->array = malloc(sizeof(int) * capacity);
	if (!stack->array)
	{
		free(stack);
		return (NULL);
	}
	stack->size = 0;
	stack->capacity = capacity;
	return (stack);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		free(stack->array);
		free(stack);
	}
}

int parse_args(int argc, char **argv, t_stack *stack_a)
{
    int i = 1;
    int num;
    char **splitted;

    if (argc == 2)
    {
        i = 0;
        splitted = ft_split(argv[1], 32);
		while (splitted[i])
		{
			if (ft_atoi(splitted[i]) == 0 && splitted[i][0] != '0')
                return (0);
			stack_a->array[i] = ft_atoi(splitted[i]);
			i++;
			stack_a->size++;
		}
        return (1);
    }
    while (i < argc)
    {
        if (!ft_str_isdigit(argv[i]))
            return (0);
        num = ft_atoi(argv[i]);
        stack_a->array[stack_a->size++] = num;
        i++;
    }
    return (1);
}


void	sort_three(t_stack *stack_a)
{
	int	a;
	int	b;
	int	c;

	if (stack_a->size != 3)
		return ;
	a = stack_a->array[0];
	b = stack_a->array[1];
	c = stack_a->array[2];
	if (a > b && b < c && a < c)
		swap_a(stack_a);
	else if (a > b && b > c)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
	else if (a > b && b < c && a > c)
		rotate_a(stack_a);
	else if (a < b && b > c && a < c)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (a < b && b > c && a > c)
		reverse_rotate_a(stack_a);
}

void	sort_simples_cases(t_stack *stack_a)
{
	if (stack_a->size == 1)
		return ;
	if (stack_a->size == 2)
	{
		if (stack_a->array[0] > stack_a->array[1])
			rotate_a(stack_a);
		return ;
	}
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		return ;
	}
}
