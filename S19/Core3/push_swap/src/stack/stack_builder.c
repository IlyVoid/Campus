#include "libs.h"

t_node	last_node(t_node **lst)
{
	t_node	*last;

	if (!lst)
		return (NULL);
	last = lst;
	while (last->next)
		last = last->next;
	return (last);
}

t_node	*new_node(int value)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_back_node(t_node **lst, t_node *new)
{
	t_node	*tmp;

	tmp = *lst;
	if (!new)
		return ;
	if (!lst)
		*lst = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	stacks_builder(char **argv, t_stacks *stacks)
{
	t_node	*new;

	stacks->a = (t_stack){0};
	stacks->b = (t_stack){0};
	while (argv[stacks->a.size])
	{
		new_node = new_node(ft_atoi(argv[stacks->a.size]));
		if (!new_node)
			prog_exit(stacks);
		add_back_node(&stacks->a.head, new_node);
		(stacks->a.size)++;
	}
}
