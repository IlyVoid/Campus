#include "../include/checker.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*push_b;

	if (!*stack_b)
		return ;
	push_b = (*stack_b)->next;
	(*stack_b)->next = *stack_a;
    *stack_a = *stack_b;
    *stack_b = push_b;
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    t_list  *push_a;

    if (!*stack_a)
        return ;
    push_a = (*stack_a)->next;
    (*stack_a)->next = *stack_b;
    *stack_b = *stack_a;
    *stack_a = push_a;
}
