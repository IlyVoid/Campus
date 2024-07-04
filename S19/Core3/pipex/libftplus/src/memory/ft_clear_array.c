#include "../../../include/libft.h"

void	ft_clear_array(char **array)
{
    int len;
    int	i;

    len = 0;
    if (!array)
        return ;
    while (array[len])
        len++;
    i = 0;
    while (i < len)
    {
        free(array[i]);
        i++;
    }
    free(array);
    array = NULL;
}
