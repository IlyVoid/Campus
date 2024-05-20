#ifndef CHECKER_H
# define CHECKER_H

# include <limits.h>
#include <threads.h>
# include "../../libftplus/include/libft.h"

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
}			t_swap;

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);

int		is_sorted(t_list *stack);

#endif
