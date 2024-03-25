/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-19 13:40:24 by user              #+#    #+#             */
/*   Updated: 2024-03-19 13:40:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    *ft_memset(void *b, int c, size_t len)
{
    char    *holder;

    holder = (char *)b;
    while (len > 0)
    {
        holder[len - 1] = c;
        len--;
    }
    return (0);
}