#include "../include/push_swap.h"

static void ft_rr(t_list **stack)
{
    t_list  *tmp;
    t_list  *end;

    if (!(*stack) || !((*stack)->next))
        return ;
    tmp = *stack;
    end = ft_lstlast(*stack);
    while ((*stack)-next->next)
        *stack = (*stack)->next;
    end->next = tmp;
    (*stack)->next = NULL;
    *stack = end;
}

void    rra(t_list **stack_a)
{
    ft_rr(stack_a);
    write(1, "rra\n", 4);
}

void    rrb(t_list **stack_b)
{
    ft_rr(stack_b);
    write(1, "rrb\n", 4);
}

void    rrr(t_list **stack_s, t_list **stack_b)
{
    ft_rr(stack_a);
    ft_rr(stack_b);
    write(1, "rrr\n", 4);
}