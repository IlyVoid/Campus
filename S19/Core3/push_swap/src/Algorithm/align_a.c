#include "push_swap.h"

void    align_a(t_stack *stacks)
{
    int     min;
    size_t  i;
    t_node  *tmp;
    char    *direction;

    i = 0;
    tmp = stacks->a.head;
    min = find_min(tmp);
    while (tmp->value != min)
    {
        tmp = tmp->next;
        i++;
    }
    if (i <= stacks->a.size / 2)
        direction = "ra";
    else
        direction = "rra";
    while (stacks->a.head->value != min)
        call_instruction(stacks, direction);
}