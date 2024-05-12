#include "push_swap.h"

/* optimizes op numb according to the position of the node in stack
store info in the struct to use when assigning the operations */

void    calculate_n_instruct_stack(t_info *info)
{
    if (info->index < (info->size / 2))
    {
        info->top = true;
        info->n_instruct = info->index;
    }
    else
    {
        info->top = false;
        info->n_instruct = info->size - info->index;
    }
}

/* add the number of operations needed in stack A and stack B
if both nodes are in tha same half, optimize the operations
 ra and rb cant be replaced by rr, per example */

void	get_total_instruct(t_actions *tmp, t_actions *def)
{
    tmp->total = tmp->a.n_instruct + tmp->b.n_instruct;
    if (!(tmp->a.top ^ tmp->b.top))
        tmp->total -= min_value(tmp->a.n_instruct, tmp->b.n_instruct);
    if (tmp->total < def->total)
        ft_memmove(def, tmp, sizeof(t_actions));
}

/* check the position in stack A where to put a given value (stack B node)
and count the number of operations needed in stack A for this
add both to get the total value */

void	get_actions_in_stack_a(t_actions *tmp, t_actions *def, t_stacks *stacks, int value)
{
    t_node  *head;
    t_node  *prev;
    int     max;

    tmp->a.index = 0;
    head = stacks->a.head;
    prev = last_node(&head);
    max = find_max(head);
    while (head)
    {
        if ((head->value > value && prev->value < value)
            || (head->value > value && prev->value == max)
            || (head->value < value && (prev->value == max && value > max)))
            break ;
        prev = head;
        head = head->next;
        (tmp->a.index)++;
    }
    calculate_n_instruct_stack(&tmp->a);
    get_total_instruct(tmp, def);
}

/* iterate over stack B to find the node in stack A
in which combined with B operations, total the least number of operations
def var is going to store the information needed to best perform */

void	get_smallest_action_push_a(t_stacks *stacks, t_actions *def)
{
    t_actions    tmp;
    t_node       *tmp_b;

    ft_bzero(&tmp, sizeof(t_actions));
    tmp.a.size = stacks->a.size;
    tmp.b.size = stacks->b.size;
    def->total = MAX_INT;
    tmp_b = stacks->b.head;
    while (tmp_b)
    {
        calculate_n_instruct_stack(&tmp.b);
        get_actions_in_stack_a(&tmp, def, stacks, tmp_b->value);
        tmp_b = tmp_b->next;
        tmp.b.index++;
    }
}