#include "libs.h"

void    prog_exit(t_stacks *stacks)
{
    ft_putendl_fd("Error", STDERR_FILENO);
    stacks_clear(stacks);
    exit(EXIT_FAILURE);
}

void    val_args(int argc, char **argv)
{
    if (argc == 1)
    {
        ft_array_clear((void **)argv);
        exit(EXIT_SUCCESS);
    }
    if (!val_params(argv))
    {
        ft_array_clear((void **)argv);
        ft_putendl_fd("Error", STDERR_FILENO);
        exit(EXIT_FAILURE);
    }
}

char    **unite_args(nt argc, char **argv)
{
    char    **argv_split;
    char    *string;
    char    *tmp;
    size_t  i;

    string = ft_strdup("");
    if (!string)
        exit(EXIT_FAILURE);
    i = 1;
    while (i < argc)
    {
        tmp = ft_strjoin(argv[i], " ");
        if (!tmp)
            exit(EXIT_FAILURE);
        string = ft_strjoin_free(string, tmp);
        if (!string)
            exit(EXIT_FAILURE);
        i++;
    }
    argv_split = ft_split(string, ' ');
    free(string);
    if (!argv_split)
        exit(EXIT_FAILURE);
    return (argv_split);
}