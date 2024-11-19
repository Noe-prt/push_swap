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
    //print_stacks(stack_a, stack_b);
    push_swap(stack_a, stack_b);
    //print_stacks(stack_a, stack_b);
    return (0);
}

void    push_swap(t_stack *stack_a, t_stack *stack_b)
{
    // TROUVER UN PUTAIN D'ALGO
    size_t  i;
    int instructions;
    int min;
    int j;


    i = 0;
    j = 0;
    instructions = 0;
    // 1 5 6 8 2
    while (stack_a->size != 0)
    {
        i = 0;
        min = stack_a->array[0];
        while (i < stack_a->size)
        {
            if (stack_a->array[i] < min)
            {
                min = stack_a->array[i];
                j = i;
            }
            i++;
        }
        while (stack_a->array[0] != min)
        {
            if ((stack_a->size - j) < stack_a->size / 2)
            {
                reverse_rotate_a(stack_a);
                printf("rra\n");
            }
            else
            {
                rotate_a(stack_a);
                printf("ra\n");
            }
            instructions++;  
        }
        push_b(stack_a, stack_b);
        printf("pb\n");
        instructions++;
    }
    while (stack_a->size != stack_a->capacity)
    {
        push_a(stack_a, stack_b);
        printf("pa\n");
        instructions++;
    }
}

void    print_stacks(t_stack *stack_a, t_stack *stack_b)
{
    printf("\nStack a:\n");
    for (size_t i = 0; i < stack_a->size; i++)
        printf("%d\n", stack_a->array[i]);

    printf("\nStack b:\n");
    for (size_t i = 0; i < stack_b->size; i++)
        printf("%d\n", stack_b->array[i]);
    printf("\n--------------------------\n");
}

void	swap_a(t_stack *stack_a)
{
	ft_swap(&stack_a->array[0], &stack_a->array[1]);
}

void	swap_b(t_stack *stack_b)
{
	ft_swap(&stack_b->array[0], &stack_b->array[1]);
}

void    sa_sb(t_stack *stack_a, t_stack *stack_b)
{
    swap_a(stack_a);
    swap_b(stack_b);
}

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	size_t	i;

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
	size_t i;

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

void    rotate_a(t_stack *stack_a)
{
    size_t i;
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
    size_t i;
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
    rotate_a(stack_a);
    rotate_b(stack_b);
}

void    reverse_rotate_a(t_stack *stack_a)
{
    size_t i;
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
    size_t i;
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
    reverse_rotate_a(stack_a);
    reverse_rotate_b(stack_b);
}

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
