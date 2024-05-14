#include "push_swap.h"

void    exit_push_swap(t_stacks *stacks)
{
    stacks_clear(stacks);
    exit(EXIT_FAILURE);
}

/* push marked nodes to b */

void    push_to_stack_b(t_stacks *stacks)
{
    int     init_size;

    init_size = stacks->a.size;
    while (init_size)
    {
        if ((t_stacks *)(stacks->a.head)->keep_a)
            call_instruction(stacks, "ra");
        else
            call_instruction(stacks, "pb");
        init_size--;
    }
}

/*