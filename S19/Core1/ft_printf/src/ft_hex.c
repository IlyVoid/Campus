#include "ft_printf.h"

void    ft_puthex_printf(unsigned int n, size_t *counter, char *base)
{
    char    *str;

    str = ft_outputhex_printf(n, base);
    ft_putstr_printf(str, counter);
    free(str);
}
