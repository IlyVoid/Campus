#include "../include/libs.h"

static void read_execute_cmds(t_stacks *stacks, bool verbose)
{
    char    *instruct;
    int     ret;
    bool    valid_instruct;

    if (verbose)
        stacks_print(*stacks);
    while (true)
    {
        ret = get_next_line(STDIN_FILENO, &instruct);
        if (ret < 0)
            prog_exit(stacks);
        if (!ret)
            break ;
        valid_instruct = instructions(instruct, stacks);
        free(instruct);
        if (!valid_instruct)
        {
            prog_exit(stacks);
        }
        if (verbose)
            stacks_print(*stacks);
    }
    free(instruct);
}

static void check_if_sorted(t_stacks *stacks)
{
    bool    sorted;

    sorted = is_sorted(stacks);
    if (sorted)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
}

int main(int argc, char **argv)
{
    t_stacks    stacks;
    char        **split_argv;
    bool        verbose;

    if (argc == 1)
        return (EXIT_FAILURE);
    verbose = !(ft_strcmp(argv[1], "-v"));
    if (verbose)
        split_argv = unite_args(--argc, &argv[1]);
    else
        split_argv = unite_args(argc, argv);
    val_args(argc, split_argv);
    stacks_builder(split_argv, &stacks);
    ft_clear_array(split_argv);
    read_execute_cmds(&stacks, verbose);
    check_if_sorted(&stacks);
    stacks_clear(&stacks);
    return (EXIT_SUCCESS);
}
