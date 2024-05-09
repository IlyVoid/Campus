#include "push_swap.h"


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
        if (tmp_leep_a > keep_a)
        {
            a->mark_head = tmp->value;
            keep_a = tmp_keep_a;
        }
        tmp = tmp->next;
    }
}

void    mark_head(t_stack *a)
{
    int     keep_a;

    find_mark_head(a);
    keep_a = kept_nodes(a, a->mark_head, true);
}