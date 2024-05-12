#ifndef LIBS_H
# define LIBS_H

# include <stdbol.h>
# include "../../../Core2/printf/include/libft.h"

typedef struct s_node
{
	int			value;
	int			index;
	bool		keep_a;
	void		*next;
}				t_node;

typedef struct s_stack
{
	t_node		*head;
	size_t		size;
	int			mark_head;
}				t_stack;

typedef	struct s_stacks
{
	t_stack		a;
	t_stack		b;
}				t_stacks;

bool			swap(t_stack *stack);
bool			push(t_stack *to, t_stack *from);
bool			rot(t_stack *stack);
bool			rotr(t_stack *stack);
char			**unite_args(int argc, char **argv);
void			val_args(int argc, char **argv);
bool			val_params(char **argv);
void			stacks_builder(char **argv, t_stacks *stacks);
bool			instructions(char *op, t_stack *stacks);
bool			is_sorted(t_stacks *stacks);
void			stacks_clear(t_stacks *stacks);
void			prog_exit(t_stacks *stacks);
void			stacks_print(t_stacks *stacks);
t_node			*new_node(int value);
void			add_back_node(t_node **lst, t_node *new);
void			add_front_node(t_node **lst, t_node *new);
t_node			last_node(t_node **lst);

#endif
