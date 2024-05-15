#include "../../includes/push_swap.h"

/* attribute node values in the array of ints */
void    attribute_values(t_node *node, int *tab, size_t size)
{
    size_t i;

    i = 0;
    while (node && i < size)
    {
        tab[i] = node->value;
        node = node->next;
        i++;
    }
}

/* sort 2 elements in the stack A */
void    sort_lst_2(t_stacks *stacks)
{
    int values[2];
    if (!stacks)
        return ;
    attribute_values(stacks->a->head, values, 2);
    if (values[0] > values[1])
        call_instruction(stacks, "sa");
}

/* sort 3 elements in the stack A without stack B */
void    sort_lst_3(t_stacks *stacks)
{
    int values[3];

    if (!stacks || stacks->a.size < 3)
        return ;
    attribute_values(stacks->a.head, values, 3);
    if (values[0] < values[1] && values[1] > values[2] && values[0] < values[2])
    {
        call_instruction(stacks, "sa");
        call_instruction(stacks, "ra");
    }
    else if(values[0] > values[1] && values[1] < values[2] && values[0] < values[2])
        call_instruction(stacks, "sa");
    else if (values[0] > values[1] && values[1] < values[2] && values[0] > values[2])
        call_instruction(stacks, "ra");
    else if (values[0] > values[1] && values[1] > values[2] && values[0] > values[2])
    {
        call_instruction(stacks, "sa");
        call_instruction(stacks, "rra");
    }
    else if (values[0] < values[1] && values[1] > values[2] && values[0] > values[2])
        call_instruction(stacks, "rra");
}

/* Iterate through the stack A and check for min and max to push to B, check head and last node as well */
void    push_min_max_value_to_b(t_stacks *stacks, int min, int max)
{
    t_node *head;
    t_node *last;
    size_t size;
    size_t i;

    i = 0;
    size = stacks->a.size;
    while (i < size)
    {
        head = stacks->a.head;
        last = last_node(&stacks->a.head);
        if (head->value == min || head->value == max)
            call_instruction(stacks, "pb");
        else if (last->value == min || last->value == max)
        {
            call_instruction(stacks, "rra");
            call_instruction(stacks, "pb");
        }
        else
            call_instruction(stacks, "ra");
        i++;
    }
}

/* push min and max values of stack A to stack B, lst size = 4 -> push min
 * sort stack A with remaining nodes and push back from B */
void    sort_lst_5(t_stacks *stacks)
{
    size_t  n_plus;
    int     min;
    int     max;

    if (!stacks || stacks->a.size < 4)
        return ;
    n_plus = stacks->a.size - 3;
    min = find_min(stacks->a.head);
    if (n_plus > 1)
        max = find_max(stacks->a.head);
    else
        max = MAX_INT;
    push_min_max_value_to_b(stacks, min, max);
    sort_lst_3(stacks);
    while (n_plus)
    {
        call_instruction(stacks, "pa");
        if (stacks->a.head->value == max)
            call_instruction(stacks, "ra");
        n_plus--;
    }
}