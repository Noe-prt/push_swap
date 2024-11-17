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
    print_stacks(stack_a, stack_b);
    swap_a(stack_a);
    print_stacks(stack_a, stack_b);
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    print_stacks(stack_a, stack_b);
    ra_rb(stack_a, stack_b);
    print_stacks(stack_a, stack_b);
    rra_rrb(stack_a, stack_b);
    print_stacks(stack_a, stack_b);
    swap_a(stack_a);
    print_stacks(stack_a, stack_b);
    push_a(stack_a, stack_b);
    push_a(stack_a, stack_b);
    push_a(stack_a, stack_b);
    print_stacks(stack_a, stack_b);
    free_stack(stack_a);
    free_stack(stack_b);
    return (0);
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

void    push_a(t_stack *stack_a, t_stack *stack_b)
{
    size_t i;

    if (stack_b->size == 0)
        return;
    
    // Décaler les éléments de stack_b vers le bas
    i = stack_a->size;
    while (i > 0)
    {
        stack_a->array[i] = stack_a->array[i - 1];
        i--;
    }

    // Ajouter le sommet de stack_a en haut de stack_b
    stack_a->array[0] = stack_b->array[0];

    // Décaler les éléments de stack_a vers le haut
    i = 0;
    while (i < stack_b->size - 1)
    {
        stack_b->array[i] = stack_b->array[i + 1];
        i++;
    }

    // Mettre à jour les tailles
    stack_b->size--;
    stack_a->size++;
}

void push_b(t_stack *stack_a, t_stack *stack_b)
{
    size_t i;

    if (stack_a->size == 0)
        return;
    
    // Décaler les éléments de stack_b vers le bas
    i = stack_b->size;
    while (i > 0)
    {
        stack_b->array[i] = stack_b->array[i - 1];
        i--;
    }

    // Ajouter le sommet de stack_a en haut de stack_b
    stack_b->array[0] = stack_a->array[0];

    // Décaler les éléments de stack_a vers le haut
    i = 0;
    while (i < stack_a->size - 1)
    {
        stack_a->array[i] = stack_a->array[i + 1];
        i++;
    }

    // Mettre à jour les tailles
    stack_a->size--;
    stack_b->size++;
}



/* ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.*/
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
