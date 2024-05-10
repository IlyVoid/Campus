#include "push_swap.h"

/* call the necessary operation to make sure that the first node is the smallest
if the minimum value is in the top bottom, operate 'ra', else operate 'rra' */

void    align_a(t_stack *stacks)
{
    int     min;
    size_t  i;
    t_node  *tmp;
    char    *instruct;

    i = 0;
    tmp = stacks->a.head;
    min = find_min(tmp);
    while (tmp->value != min)
    {
        tmp = tmp->next;
        i++;
    }
    if (i <= stacks->a.size / 2)
        instruct = "ra";
    else
        instruct = "rra";
    while (stacks->a.head->value != min)
        call_instruction(stacks, instruct);
}