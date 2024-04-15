/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:03:45 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/15 11:34:52 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*holder;
	size_t			i;

	i = 0;
	holder = (unsigned char *)b;
	if (!holder)
		return  (NULL);
	while (i < len)
	{
		holder[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
