/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:55:37 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/03 11:55:39 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_printf(int n, size_t *counter)
{
	if (n == -2147483648)
	{
		ft_putstr_printf("-2147483648", counter);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_printf('-', counter);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_printf((n / 10), counter);
	ft_putchar_printf(('0' + n % 10), counter);
}

void	ft_putuint_printf(unsigned int n, size_t *counter)
{
	if (n > 9)
		ft_putuint_printf((n / 10), counter);
	ft_putchar_printf(('0' + n % 10), counter);
}