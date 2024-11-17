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
        printf("%d	%d\n", stack_a->array[i], stack_b->array[i]);

    //swap_a(stack_a);
	//push_b(stack_a, stack_b);
    rotate_a(stack_a);
    printf("\nStack after operations:\n");
    for (size_t i = 0; i < stack_a->size; i++)
        printf("%d	%d\n", stack_a->array[i], stack_b->array[i]);

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

void    push_a(t_stack *stack_a, t_stack *stack_b)
{
    size_t i;

    if (stack_b->size == 0)
        return;
    stack_a->array[stack_a->size] = stack_b->array[0];
    stack_a->size++;
    i = 0;
    while (i < stack_b->size - 1)
    {
        stack_b->array[i] = stack_b->array[i + 1];
        i++;
    }
    stack_b->size--;
}

void    push_b(t_stack *stack_a, t_stack *stack_b)
{
    size_t i;

    if (stack_a->size == 0)
        return ;
    stack_b->array[stack_b->size] = stack_a->array[0];
    stack_b->size++;
    i = 0;
    while (i < stack_a->size - 1)
    {
        stack_a->array[i] = stack_a->array[i + 1];
        i++;
    }
    stack_a->size--;
}


/* ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.*/
void    rotate_a(t_stack *stack_a)
{
    size_t i;
    int temp;

    if (stack_a->size == 0)
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

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}
