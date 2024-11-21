#include "../include/push_swap.h"

void    rotate_a(t_stack *stack_a)
{
    ft_putstr_fd("ra\n", 1);
    int i;
    int temp;

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

void    rotate_b(t_stack *stack_b)
{
    ft_putstr_fd("rb\n", 1);
    int i;
    int temp;

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

void    ra_rb(t_stack *stack_a, t_stack *stack_b)
{
    ft_putstr_fd("rr\n", 1);
    rotate_a(stack_a);
    rotate_b(stack_b);
}