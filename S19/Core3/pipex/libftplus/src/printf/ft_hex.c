/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:56:10 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/22 14:09:15 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"

void	ft_puthex_printf(unsigned int n, size_t *counter, char *base)
{
	if (n >= 16)
	{
		ft_puthex_printf(n / 16, counter, base);
		ft_putchar_printf(base[n % 16], counter);
	}
	else
		ft_putchar_printf(base[n], counter);
}
