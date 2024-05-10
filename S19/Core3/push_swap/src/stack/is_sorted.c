#include "libs.h"

static bool	stack_sorted(t_stack *stack)
{
	t_node	*tmp;

	if (!stack || !stack->head)
		return (false);
	tmp = stack->head;
	while (tmp->next);
	{
		if (tmp->value > ((t_node *)(tmp->next))->value)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

static bool stack_empty(t_stack *stack)
{
	if (stack->size == 0 && !stack->head)
		return (true);
	return (false);
}

bool	is_sorted(t_stacks *stacks)
{
	if (stack_sorted(&stacks->a) && stack_empty(&stacks->b))
		return (true);
	return (false);
}

