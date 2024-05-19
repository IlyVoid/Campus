#include "../include/push_swap.h"

int check_sorting(t_list **stack_a)
{
    t_list  *tmp;

    tmp = *stack_a;
    while (tmp && tmp->next)
    {
        if (tmp->content > tmp->next->content)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

int check_sorting_a(t_list **stack_a, int count)
{
    int len;

    len = ft_lstsize(*stack_a);
    if (len != count)
        return (0);
    if (check_sorting(stack_a) == 0)
        return (0);
    return (1);
}

t_list  *find_min_lst(t_list **stack)
{
    t_list  *min;
    t_list  *tmp;

    min = *stack;
    tmp = *stack;
    while (tmp)
    {
        if (tmp->content < min->content)
            min = tmp;
        tmp = tmp->next;
    }
    return (min);
}

t_list  *find_max_lst(t_list **stack)
{
    t_list  *max;
    t_list  *tmp;

    max = *stack;
    tmp = *stack;
    while (tmp)
    {
        if (tmp->content > max->content)
            max = tmp;
        tmp = tmp->next;
    }
    return (max):
}

int is_rev_sorted(t_swap *tab)
{
    t_list *tmp;

    tmp = tab->stack_a;
    while (tmp->next)
    {
        if (tmp->content < tmp->next->content)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}