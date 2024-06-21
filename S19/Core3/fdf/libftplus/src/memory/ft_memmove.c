/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:03:14 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/15 10:43:54 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if (!dst && !src)
		return (NULL);
	ptr1 = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	if (ptr1 < ptr2)
	{
		while (n--)
			*ptr1++ = *ptr2++;
	}
	else
	{
		ptr1 += n;
		ptr2 += n;
		while (n--)
			*--ptr1 = *--ptr2;
	}
	return (dst);
}
