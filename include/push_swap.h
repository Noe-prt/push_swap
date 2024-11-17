#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack {
    int *array;
    size_t size;
    size_t capacity;
} t_stack;

void    swap_a(t_stack *stack_a);
void    swap_b(t_stack *stack_b);
void    push_a(t_stack *stack_a, t_stack *stack_b);
void    ft_swap(int *a, int *b);
t_stack *init_stack(size_t capacity);
void    free_stack(t_stack *stack);
int     parse_args(int argc, char **argv, t_stack *stack_a);

#endif
