#include "../include/push_swap.h"

t_stack *init_stack(size_t capacity)
{
    t_stack *stack = malloc(sizeof(t_stack));
    if (!stack)
        return (NULL);
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

void free_stack(t_stack *stack)
{
    if (stack)
    {
        free(stack->array);
        free(stack);
    }
}

int parse_args(int argc, char **argv, t_stack *stack_a)
{
    int  i;

    i = 1;
    while (i < argc)
    {
        int num = atoi(argv[i]);
        stack_a->array[stack_a->size++] = num;
        i++;
    }
    return (1);
}
