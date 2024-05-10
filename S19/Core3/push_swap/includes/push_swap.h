#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include "libs.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_info
{
    char        instruct[4];
    bool        top;
    int         n_instruct;
    int         index;
    int         size;
}               t_info;

typedef struct s_actions
{
    t_info      a;
    t_info      b;
    int         total;
    char        instruct_same[4];
    int         n_instruct_same;
}               t_actions;

/* SORTING ALGORITHM */
void    sort_lst_2(t_stack *stacks);
void    sort_lst_3(t_stack *stacks);
void    sort_lst_5(t_stack *stacks);

/* SORTING ALGORITHM UTIL */
void    mark_head(t_stack *a);
void    get_smallest_action_push_a(t_stacks *stacks, t_actions *def);
void    attribute_instruction(t_actions *def);
void    instruction_act(t_stacks *stacks, t_actions *def);
void    align_a(t_stack *stacks);
void    exit_push_swap(t_stacks *stacks);

/* UTILS */
void    call_instruction(t_stacks *stacks, char *instruct);
int     find_min(t_node *head);
int     find_max(t_node *head);
int     min_value(bool a, bool b);

#endif