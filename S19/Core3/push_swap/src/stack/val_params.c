#include "libs.h"

static bool num_param_check(char **argv)
{
    int param;
    int c_count;

    param = 0;
    while (argv[param])
    {
        c_count = 0;
        if (argv[param][c_count] == '-')
            c_count++;
        if (!ft_isdigit(argv[param][c_count]))
            return (false);
        while (argv[param][c_count])
        {
            if (!ft_isdigit(argv[param][c_count]))
                return (false);
            c_count++;
        }
        param++;
    }
    return (true);
}

static bool num_range_check(char *str, char *limit)
{
    int i;

    if (ft_strlen(str) > ft_strlen(limit))
        return (false);
    if (ft_strlen(str) < ft_strlen(limit))
        return (true);
    i = 0;
    while (str[i] == limit[i])
    {
        if (!str[i])
            return (true);
        i++;
    }
    if (str[i] > limit[i])
        return (false);
    return (true);
}

static bool int_param_check(char **argv)
{
    int param;
    char *limit;

    param = 0;
    while (argv[param])
    {
        limit = "2147483647";
        if (ft_strlen(argv[param]) == ft_strlen(limit))
        {
            if (!num_range_check(argv[param], limit))
                return (false);
        }
        else
        {
            limit = "2147483648";
            if (!num_range_check(argv[param], limit))
                return (false);
        }
        param++;
    }
    return (true);
}

static bool dup_param_check(char **argv)
{
    int i;
    int j;

    i = 0;
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (!ft_strcmp(argv[i], argv[j]))
                return (false);
            j++;
        }
        i++;
    }
    return (true);
}

bool val_params(char **argv)
{
    if (!num_param_check(argv))
        return (false);
    if (!int_param_check(argv))
        return (false);
    if (!dup_param_check(argv))
        return (false);
    return (true);
}