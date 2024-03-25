/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-03-20 12:09:36 by user              #+#    #+#             */
/*   Updated: 2024-03-20 12:09:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strdup(const char *s1)
{
    char    *dup;
    int     i;
    int     len;

    i = 0;
    len = ft_strlen(s1);
    dup = (char *)malloc(sizeof(char) * (len + 1));
    if (!dup)
        return (NULL);
    while (i < len)
    {
        dup[i] = s1[i]
            i++;
    }
    dup[i] = '\0';
    return (dup);
}
