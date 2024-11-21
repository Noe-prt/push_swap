#include "../include/push_swap.h"

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
    printf("pa\n");
	int	i;

	i = stack_a->size;
	if (stack_b->size == 0)
		return ;
	while (i > 0)
	{
		stack_a->array[i] = stack_a->array[i - 1];
		i--;
	}
	stack_a->array[0] = stack_b->array[0];
	stack_a->size++;
	stack_b->size--;
	while (i < stack_b->size)
	{
		stack_b->array[i] = stack_b->array[i + 1];
		i++;
	}
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
    printf("pb\n");
	int i;

	i = stack_b->size;
	if (stack_a->size == 0)
		return ;
	while (i > 0)
	{
		stack_b->array[i] = stack_b->array[i - 1];
		i--;
	}
	stack_b->array[0] = stack_a->array[0];
	stack_b->size++;
	stack_a->size--;
	while (i < stack_a->size)
	{
		stack_a->array[i] = stack_a->array[i + 1];
		i++;
	}
}