#include "../../includes/libs.h"

void	stacks_print(t_stacks *stacks)
{
	size_t	i;

	i = 0;
	ft_printf("\nsize:\t%i\t%i\nstack:", stacks->a.size, stacks->b.size);
	while (i < stacks->a.size || i < stacks->b.size)
	{
		if (i < stacks->a.size)
		{
			ft_printf("\t%i", stacks->a.head->value);
			if (stacks->a.head->value)
				stacks->a.head = stacks->a.head->next;
		}
		else
			ft_printf("\t");
		if (i < stacks->b.size)
		{
			ft_printf("\t%i", stacks->b.head->value);
			if (stacks->b.head->value)
				stacks->b.head = stacks->b.head->next;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\t_\t_\n\ta\tb\n> ");
}
