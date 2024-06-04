/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:33:12 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/04 17:33:18 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/ft_printf.h"

void	ft_puthex_printf(unsigned int number, size_t *counter, char *base)
{
	char	*str;

	str = ft_outputhex_printf(number, base);
	ft_putstring_printf(str, counter);
	free(str);
}
