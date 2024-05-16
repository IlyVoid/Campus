#include "../../includes/push_swap.h"

/* according to the info stored in the struct, assign the operations
if both nodes are in the same half, optimize the operations (rr or rrr)
and recalculate instruct in each stack */

void    attribute_instruction(t_actions *def)
{
    if (!(def->a.top ^ def->b.top))
    {
        def->n_instruct_same = min_value(def->a.top, def->b.top);
        def->b.n_instruct = def->n_instruct_same;
        def->a.n_instruct = def->n_instruct_same;
    }
    if (def->a.top == true)
    {
        ft_memmove((char *)&def->a.instruct, "ra", 4);
        ft_memmove((char *)&def->instruct.same, "rr", 4);
    }
    else
    {
        ft_memmove((char *)&def->a.instruct, "rra", 4);
        ft_memmove((char *)&def->instruct.same, "rrr", 4);
    }
    if (def->b.top == true)
        ft_memmove((char *)&def->b.instruct, "rb", 4);
    else
        ft_memmove((char *)&def->b.instruct, "rrb", 4);
}

/* call the operations according to best perform stored in def */

void    instruction_act(t_stacks *stacks, t_actions *def)
{
    while (def->n_instruct_same--)
        call_instruction(stacks, def->instruct.same);
    while (def->a.n_instruct--)
        call_instruction(stacks, def->a.instruct);
    while (def->b.n_instruct--)
        call_instruction(stacks, def->b.instruct);
}
