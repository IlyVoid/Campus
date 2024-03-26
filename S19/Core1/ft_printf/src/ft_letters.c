#include "ft_printf.h"

void	ft_putchar_printf(char c, size_t *counter)
{
	write(1, &c, 1);
	*counter += 1;
}

void	ft_putstr_printf(char *str, size_t *counter)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		ft_putchar_printf(*str, counter);
		str++;
	}
}
