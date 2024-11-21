#include "../include/push_swap.h"

void    reverse_rotate_a(t_stack *stack_a)
{
    printf("rra\n");
    int i;
    int temp;

    if (stack_a->size <= 1)
        return ;
    i = stack_a->size;
    temp = stack_a->array[stack_a->size - 1];
    while (i > 0)
    {
        stack_a->array[i] = stack_a->array[i - 1];
        i--;
    }
    stack_a->array[0] = temp;
}

void    reverse_rotate_b(t_stack *stack_b)
{
    printf("rrb\n");
    int i;
    int temp;

    if (stack_b->size <= 1)
        return ;
    i = stack_b->size;
    temp = stack_b->array[stack_b->size - 1];
    while (i > 0)
    {
        stack_b->array[i] = stack_b->array[i - 1];
        i--;
    }
    stack_b->array[0] = temp;
}

void    rra_rrb(t_stack *stack_a, t_stack *stack_b)
{
    printf("rrr\n");
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
}