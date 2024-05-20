#include "../include/checker.h"

static void ft_rr(t_list **stack)
{
    t_list  *tmp;
    t_list  *end;

    if (!(*stack) || !((*stack)->next))
        return ;
    tmp = *stack;
    end = ft_lstlast(*stack);
    while ((*stack)->next->next)
        *stack = (*stack)->next;
    end->next = tmp;
    (*stack)->next = NULL;
    *stack = end;
}

void    rra(t_list **stack_a)
{
    ft_rr(stack_a);
}

void    rrb(t_list **stack_b)
{
    ft_rr(stack_b);
}
