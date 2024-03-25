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

int ft_atoi(const char *str)
{
    char    sign;
    int     i;
    int     res;

    i = 0;
    res = 0;
    sign = 1;
    while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str == '-')
            sign = -1;
        i++;
    }
    while ((str[i] >= '0' && str[i] <= '9') && str[i])
    {
        res = res * 10 + (str[i] - 48);
        i++;
    }
    return (res * sign);
}
