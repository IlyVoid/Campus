/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 16:27:34 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/03 16:27:50 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int i)
{
	if (('0' <= i && i <= '9') || ('A' <= i && i <= 'Z')
		|| ('a' <= i && i <= 'z'))
		return (1);
	return (0);
}
