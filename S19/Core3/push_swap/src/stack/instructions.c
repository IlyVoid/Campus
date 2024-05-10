#include "libs.h"

bool	instructions(char *instruct, t_stack *stacks)
{
	bool	valid;

	valid = false;
	if (!ft_strcmp(instruct, "pa"))
		valid = push(&stacks->a, &stacks->b);
	if (!ft_strcmp(instruct, "pb"))
		valid = push(&stacks->b, &stacks->a);
	if (!ft_strcmp(instruct, "sa") || !ft_strcmp(instruct, "ss"))
		valid = swap(stacks->a);
	if (!ft_strcmp(instruct, "sb") || !ft_strcmp(instruct, "ss"))
		valid = swap(stacks->a);
	if (!ft_strcmp(instruct, "ra") || !ft_strcmp(instruct, "rr"))
		valid = rot(stacks->a);
	if (!ft_strcmp(instruct, "rb") || !ft_strcmp(instruct, "rr"))
		valid = rot(stacks->b);
	if (!ft_strcmp(instruct, "rra") || !ft_strcmp(instruct, "rrr"))
		valid = rotr(stacks->a);
	if (!ft_strcmp(instruct, "rrb") || !ft_strcmp(instruct, "rrr"))
		valid = rotr(stacks->b);
	return (valid);
}
