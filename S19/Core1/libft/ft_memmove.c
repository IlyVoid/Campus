/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:03:14 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/14 12:24:43 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	unsigned char		*temp;

	if (dst == NULL && src == NULL)
		return (NULL);

	d = (unsigned char *)dst;
	s = (const unsigned char *)src;

	if (d == s)
	{
		temp = (unsigned char *)malloc(n);
		if (temp == NULL)
			return (NULL);
		while (n--)
			temp[n] = s[n];
		while (n--)
			d[n] = temp[n];
		free(temp);
	}
	else if (d > s && d < s + n)
	{
		while (n--)
			*(d + n) = *(s + n);
	}
	else
	{
		while (n--)
			*d++ = *s++;
	}
	return (dst);
}
