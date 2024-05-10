#include "libs.h"

bool	push(t_stack *to, t_stack *from)
{
	t_node	move;

	if (from->size < 1 || !from->head)
		return (true);
	move = from->head;
	from->head = from->head->next;
	move = NULL;
	add_front_node(&to->head, move);
	to->size++;
	from->size--;
	return (true);
}
