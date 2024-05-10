#include "push_swap.h"

/* starting from the mark head, a node is going to be kept in the stack A
if its index is bigger than the previous one.
the nodes that do not satisfy this condition are marked as
false and are pushed to the stack B */

static int  kept_nodes(t_stack *a, int mark_head, bool def)
{
    t_node  *tmp;
    int     cmp_value;
    int     keep_a;

    keep_a = 0;
    tmp = a->head;
    while (tmp->value != mark_head)
    {
        tmp = tmp->next;
    }
    cmp_value = tmp->value;
    while (tmp)
    {
        if (tmp->value > cmp_value)
        {
            if (def == true)
                tmp->keep = true;
            keep_a++;
            cmp_value = tmp->value;
        }
        tmp = tmp->next;
    }
    return (keep_a);
}

/* iterate over all the elements in stack A
for each node as mark head, calculate the number of nodes kept in stack A */

static void find_mark_head(t_stack *a)
{
    t_node  *tmp;
    int     keep_a;
    int     tmp_keep_a;

    keep_a = 0;
    tmp_keep_a = 0;
    tmp = a->head;
    while (tmp)
    {
        tmp_keep_a = kept_nodes(a, tmp->value, false);
        if (tmp_keep_a > keep_a)
        {
            a->mark_head = tmp->value;
            keep_a = tmp_keep_a;
        }
        tmp = tmp->next;
    }
}

/* find the mark head
the element that will keep the greatest amount of nodes in the stack A
then tag the nodes according to the best performing mark head */

void    mark_head(t_stack *a)
{
    int     keep_a;

    find_mark_head(a);
    keep_a = kept_nodes(a, a->mark_head, true);
}