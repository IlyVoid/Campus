#include "../include/push_swap.h"

void    begin_sorting(t_list **stack_a, t_list **stack_b, t_push *push, int count)
{
    int i;

    i = -1;
    while (++i < count)
    {
        if ((*stack_a)->index <= push->mid)
            pb(stack_a, stack_b);
        else
        {
            if (ft_lstsize(*stack_b) > 1 && (*stack_b)->index < (push->mid / 2))
                rr(stack_a, stack_b);
            else
                ra(stack_a);
        }
    }
    push->max = push->mid;
    push->mid = (push->max - push->next) / 2 + push->next;
    push->flag++;
}

void    find_next(t_list **stack_a, t_list **stack_b, t_push *push)
{
    if (ft_lstsize(*stack_b) > 0 && ((*stack_b)->index == push->next))
        pa(stack_a, stack_b);
    else if ((*stack_a)->index == push->next)
    {
        (*stack_a)->flag = -1;
        ra(stack_a);
        push->next++;
    }
    else if ((ft_lstsize(*stack_b)) > 2 && ft_lstlast(*stack_b)->index == push->next)
        rrb(stack_b);
    else if ((*stack_a)->next->index == push->next)
        sa(stack_a);
    else if ((ft_lstsize(*stack_a)) > 1 && ((*stack_a)->next->index == push->next)
        && ((*stack_b)->next->index == push ->next +1))
        ss(stack_a, stack_b);
    else
        return ;
    find_next(stack_a, stack_b, push);
}

void    quick_a(t_list **stack_a, t_list **stack_b, t_push *push)
{
    int count_b;
    int     i;

    i = -1;
    count_b = ft_lstsize(*stack_b);
    while (ft_lstsize(*stack_b) && ++i < count_b)
    {
        if ((*stack_b)->index == push->next)
            find_next(stack_a, stack_b, push);
        else if ((*stack_b)->flag >= push->mid)
        {
            (*stack_b)->flag = push->flag;
            pa(stack_a, stack_b);
        }
        else if ((*stack_b)-> < push->mid)
            rb(stack_b);
    }
    push->max = push->mid;
    push->mid = (push->max - push->next) / 2 + push->next;
    push->flag++;
}

void    quick_b(t_list **stack_a, t_list **stack_b, t_push *push)
{
    int now_flag;

    now_flag = (*stack_a)->flag;
    if ((*stack_a)->flag != 0)
    {
        while ((*stack_a)->flag == now_flag)
        {
            if ((*stack_a)->index != push->next)
                pb(stack_a, stack_b);
            find_next(stack_a, stack_b, push);
        }
    }
    else if ((*stack_a)->flag == 0)
    {
        while ((*stack_a)->flag != -1)
        {
            if ((*stack_a)->index != push->next)
                pb(stack_a, stack_b);
            find_next(stack_a, stack_b, push);
        }
    }
    if (ft_lstsize(*stack_b))
        push->max = (find_max_lst(stack_b))->index;
    push->mid = (push->max - push->next) / 2 + push->next;
}

void    quick_sort(t_list **stack_a, t_list **stack_b, int count)
{
    t_push  push;

    push.next = find_min_lst(stack_a)->index;
    push.max = find_max_lst(stack_a)->index;
    push.mid = push.max / 2 + push.next;
    push.flag = 0;
    begin_sorting(stack_a, stack_b, &push, count);
    while (!(check_sorting_a(stack_a, count)))
    {
        if (ft_lstsize(*stack_b) == 0)
            quick_b(stack_a, stack_b, &push);
        else
            quick_a(stack_a, stack_b, &push);
    }
}
