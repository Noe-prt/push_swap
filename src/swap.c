#include "../include/push_swap.h"

void	swap_a(t_stack *stack_a)
{
    printf("sa\n");
	ft_swap(&stack_a->array[0], &stack_a->array[1]);
}

void	swap_b(t_stack *stack_b)
{
    printf("sb\n");
	ft_swap(&stack_b->array[0], &stack_b->array[1]);
}

void    sa_sb(t_stack *stack_a, t_stack *stack_b)
{
    printf("ss\n");
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