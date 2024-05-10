#include "libs.h"

bool	rotr(t_stack *stack)
{
	t_node	*move;
	int		i;

	if (stack->size < 2 || !stack->head)
		return (true);
	i = 0;
	move = stak->head;
	while (((t_node *)(move->next))->next)
		move = move->next;
	((t_node *)(move->next))->next = stack->head;
	stack->head = move->next;
	move->next = NULL;
	return (true);
}
