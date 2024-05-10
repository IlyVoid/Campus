#include "libs.h"

bool	rot(t_stack *stack)
{
	t_node	*move;

	if (stack->size < 2 || !stack->head)
		return (true);
	move = stack->head;
	stack->head = stack->head->next;
	move->next = NULL;
	add_back_node(&stack->head, move);
	return (true);
}
