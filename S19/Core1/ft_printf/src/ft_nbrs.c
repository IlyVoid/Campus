#include "ft_printf.h"

void	ft_putnbr_printf(int n, size_t *counter)
{
	if (n == -2147483648)
	{
		ft_putnbr_printf((n / 10), counter);
		ft_putchar_printf('8', counter);
	}
	else if (n < 0)
	{
		ft_putchar_printf('-', counter);
		ft_putnbr_printf(-n, counter);
	}
	else
	{
		if (n > 9)
			ft_putnbr_printf((n / 10), counter);
		ft_putchar_printf(('0' + n % 10), counter);
	}
}

void	ft_putuint_printf(unsigned int n, size_t *counter)
{
	if (n > 9)
		ft_putuint_printf((n / 10), counter);
	ft_putchar_printf(('0' + n % 10), counter);
}
