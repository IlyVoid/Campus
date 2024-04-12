/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:02:14 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/12 14:25:48 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
    size_t  i;
    const unsigned char *str;

    i = 0;
    str = (const unsigned char *)s;
    if (!str)
        return (NULL);
    while (i < n)
    {
        if (str[i] == (unsigned char)c)
            return ((void *)&str[i]);
        i++;
    }
    return (NULL);
}
/*
#include <stdio.h>
int	main()
{
	printf("%p", ft_memchr("Hey", 'e', 6));
}
*/
