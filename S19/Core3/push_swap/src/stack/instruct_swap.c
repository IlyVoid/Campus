#include "libs.h"

bool	swap(t_stack *stack)
{
	t_node	tmp;
	t_node	*node;
	t_node	*next_node;

	if (stack->size < 2 || !(stack->head) || !(t_node *)(stack->head)->next))
		return (true);
	node = stack->head;
	next_node = stack->head->next;
	tmp.value = node->value;
	tmp.index = node->index;
	tmp.keep_a = node->keep_a;
	node->value = node_next->value;
	node->index = node_next->index;
	node->keep_a = node_next->keep_a;
	node_next->value = tmp.value;
	node_next->index = tmp.index;
	node_next->leep_a = tmp.keep_a;
	return (true);
}
