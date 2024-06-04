/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:33:29 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/04 17:33:31 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

void	ft_formatter(va_list va, char *str, size_t *counter)
{
	if (*str == 'c')
		ft_putchar_printf(va_arg(va, int), counter);
	else if (*str == 's')
		ft_putstring_printf(va_arg(va, char *), counter);
	else if (*str == 'p')
		ft_putpointer_printf(va_arg(va, void *), counter);
	else if (*str == 'i' || *str == 'd')
		ft_putnumber_printf(va_arg(va, int), counter);
	else if (*str == 'u')
		ft_putunsignedint_printf(va_arg(va, unsigned int), counter);
	else if (*str == 'x')
		ft_puthex_printf(va_arg(va, unsigned int), counter, HEX_LOW_BASE);
	else if (*str == 'X')
		ft_puthex_printf(va_arg(va, unsigned int), counter, HEX_UPP_BASE);
	else if (*str == '%')
		ft_putchar_printf(*str, counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	va;
	size_t	counter;

	if (!str)
		return (0);
	counter = 0;
	va_start(va, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_formatter(va, (char *)str, &counter);
		}
		else
			ft_putchar_printf(*str, &counter);
		str++;
	}
	va_end(va);
	return (counter);
}
