#include "../include/checker.h"

static void ft_s(t_list **stack)
{
    t_list  *tmp;

    if (!(*stack) || !((*stack)->next))
        return ;
    tmp = *stack;
    *stack = (*stack)->next;
    tmp->next = (*stack)->next;
    (*stack)->next = tmp;
}

void    sa(t_list **stack_a)
{
    ft_s(stack_a);
}

void    sb(t_list **stack_b)
{
    ft_s(stack_b);
}

void    ss(t_list **stack_a, t_list **stack_b)
{
    ft_s(stack_a);
    ft_s(stack_b);
}
