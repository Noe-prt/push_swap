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
    push_swap(stack_a, stack_b);
    return (0);
}

int get_target_b_value(int value, t_stack *stack_b)
{
    if (!stack_b || stack_b->size <= 0)
        return 0;

    int closest_smaller;
    int max_value;
    int current;
    size_t  i;

    closest_smaller = INT_MIN;
    max_value = INT_MIN;
    i = 0;
    current = stack_b->array[0];
    while (i < stack_b->size)
    {
        current = stack_b->array[i];
        if (current > max_value)
            max_value = current;
        if (current < value && current > closest_smaller)
            closest_smaller = current;
        i++;
    }
    if (closest_smaller == INT_MIN)
        return (max_value);
    return (closest_smaller);
}

int get_target_a_value(int value, t_stack *stack_a)
{
    if (!stack_a || stack_a->size <= 0)
        return 0;

    int closest_greater;
    int min_value;
    int current;
    size_t i;

    closest_greater = INT_MAX;
    min_value = INT_MAX;
    i = 0;

    while (i < stack_a->size)
    {
        current = stack_a->array[i];
        if (current < min_value)
            min_value = current;
        if (current > value && current < closest_greater)
            closest_greater = current;
        i++;
    }
    if (closest_greater == INT_MAX)
        return (min_value);
    return (closest_greater);
}


int get_push_cost(int value, int target_value, t_stack *stack_a, t_stack *stack_b)
{
    int cost = 0;
    size_t i = 0;
    int rotations_a, reverse_rotations_a;
    int rotations_b, reverse_rotations_b;

    while (stack_a->array[i] != value)
        i++;
    rotations_a = i;
    reverse_rotations_a = stack_a->size - i;
    i = 0;
    while (stack_b->array[i] != target_value)
        i++;
    rotations_b = i;
    reverse_rotations_b = stack_b->size - i;
    if (rotations_a <= reverse_rotations_a)
        cost += rotations_a;
    else
        cost += reverse_rotations_a;
    if (rotations_b <= reverse_rotations_b)
        cost += rotations_b;
    else
        cost += reverse_rotations_b;
    return cost;
}

void rotate_stacks_to_top(int value, int target_value, t_stack *stack_a, t_stack *stack_b)
{
    size_t index_a = 0;
    size_t index_b = 0;

    while (stack_a->array[index_a] != value)
        index_a++;
    while (stack_b->array[index_b] != target_value)
        index_b++;

    if (index_a < stack_a->size / 2)
    {
        while (stack_a->array[0] != value)
            rotate_a(stack_a);
    }
    else
    {
        while (stack_a->array[0] != value)
            reverse_rotate_a(stack_a);
    }
    if (index_b < stack_b->size / 2)
    {
        while (stack_b->array[0] != target_value)
            rotate_b(stack_b);
    }
    else
    {
        while (stack_b->array[0] != target_value)
            reverse_rotate_b(stack_b);
    }
}

void    move_min_value_on_top(t_stack *stack_a)
{
    size_t  i;
    int min;

    i = 0;
    min = stack_a->array[0];
    while (i < stack_a->size)
    {
        if (min > stack_a->array[i])
            min = stack_a->array[i];
        i++;
    }
    while (stack_a->array[0] != min)
    {
        rotate_a(stack_a);
    }
}

void    push_swap(t_stack *stack_a, t_stack *stack_b)
{
    // TURK ALGORITHM
    int lower_push_cost;
    int value;
    int target_value;
    int push_cost;
    size_t  i;

    i = 0;
    // First Step : Push the two firsts numbers of A in B
    push_b(stack_a, stack_b);
    push_b(stack_a, stack_b);
    /* Second step : Push the rest of A in B in
       the push cost order until he left 3 numbers in A*/
    while (stack_a->size > 3)
    {
        i = 0;
        value = stack_a->array[i];
        target_value = get_target_b_value(value, stack_b);
        push_cost = get_push_cost(value, target_value, stack_a, stack_b);
        lower_push_cost = push_cost;
        while (i < stack_a->size)
        {
            int current_value = stack_a->array[i];
            int current_target = get_target_b_value(current_value, stack_b);
            int current_cost = get_push_cost(current_value, current_target, stack_a, stack_b);

            if (current_cost < lower_push_cost)
            {
                lower_push_cost = current_cost;
                value = current_value;
                target_value = current_target; // Met à jour également target_value !
            }
            i++;
        }
        rotate_stacks_to_top(value, target_value, stack_a, stack_b);
        push_b(stack_a, stack_b);
        if (stack_a->array[2] > stack_a->array[1] && stack_a->array[2] > stack_a->array[0])
            swap_a(stack_a);

    }
    i = 0;
    while (stack_b->size > 0)
    {
        value = stack_b->array[i];
        target_value = get_target_a_value(value, stack_a);
        while (stack_a->array[0] != target_value)
        {
            rotate_a(stack_a);
        }
        push_a(stack_a, stack_b);

    }
    move_min_value_on_top(stack_a);
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

void	push_a(t_stack *stack_a, t_stack *stack_b)
{
    printf("pa\n");
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
    printf("pb\n");
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
    printf("ra\n");
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
    printf("rb\n");
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
    printf("rr\n");
    rotate_a(stack_a);
    rotate_b(stack_b);
}

void    reverse_rotate_a(t_stack *stack_a)
{
    printf("rra\n");
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
    printf("rrb\n");
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
    printf("rrr\n");
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
