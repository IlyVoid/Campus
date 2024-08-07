/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 09:54:26 by quvan-de          #+#    #+#             */
/*   Updated: 2024/07/04 14:02:10 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

int	ft_isalnum(int i)
{
	if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') || (i >= 'a'
			&& i <= 'z'))
		return (1);
	return (0);
}
