/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:56:10 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/03 12:00:02 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex_printf(unsigned int n, size_t *counter, char *base)
{
	char	*str;

	str = ft_outputhex_printf(n, base);
	ft_putstr_printf(str, counter);
	free(str);
}
