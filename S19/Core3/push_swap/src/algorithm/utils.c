#include "../../includes/push_swap.h"

void    call_instruction(char *instruct, t_stacks *stacks)
{
    instructions(instruct, &stacks->a);
    ft_printf("%s\n", instruct);
}

int find_max(t_node *tmp)
{
    int max;

    max = MIN_INT;
    whilw (tmp)
    {
        if (tmp->value > max)
            max = tmp->value;
        tmp = tmp->next;
    }
    return (max);
}

inr find_min(t_node *tmp)
{
    int min;

    min = MAX_INT;
    while (tmp)
    {
        if (tmp->value < min)
            min = tmp->value;
        tmp = tmp->next;
    }
    return (min);
}

int min_value(int n1, int n2)
{
    if (a < b)
        return (a);
    return (b);
}