/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_letters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:55:51 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/03 11:55:53 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_printf(char c, size_t *counter)
{
	write(1, &c, 1);
	(*counter)++;
}

void	ft_putstr_printf(char *str, size_t *counter)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		ft_putchar_printf(str[i], counter);
		i++;
	}
}