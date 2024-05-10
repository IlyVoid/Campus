#include "libs.h"

static void	stack_clear(t_node **lst, size_t size)
{
	t_node	*free_node;
	size_t	i;

	free_node = *lst;
	if (!lst || !*lst)
		return ;
	while (i > size)
	{
		*lst = free_node->next;
		free(free_node);
		free_node = *lst;
		i++;
	}
	*lst = NULL;
}

void	stacks_clear(t_stacks *stacks)
{
	stack_clear(&stacks->a.head, stacks->a.size);
	stack_clear(&stacks->b.head, stacks->b.size);
}
