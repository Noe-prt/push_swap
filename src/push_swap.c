#include "../include/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

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

    printf("Initial stack:\n");
    for (size_t i = 0; i < stack_a->size; i++)
        printf("%d\n", stack_a->array[i]);

    swap_a(stack_a);
    printf("\nStack after operations:\n");
    for (size_t i = 0; i < stack_a->size; i++)
        printf("%d\n", stack_a->array[i]);

    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
}

void	swap_a(t_stack *stack_a)
{
	ft_swap(&stack_a->array[0], &stack_a->array[1]);
}

void	swap_b(t_stack *stack_b)
{
	ft_swap(&stack_b->array[0], &stack_b->array[1]);
}

void    push_a(t_stack *stack_a, t_stack *stack_b);

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
