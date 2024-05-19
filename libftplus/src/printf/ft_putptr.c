/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:57:16 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/22 15:49:34 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_printf.h"
#include "../../include/libft.h"

size_t	ft_len(unsigned long long n, char *base)
{
	size_t	len;
	size_t	base_len;

	len = 1;
	base_len = ft_strlen(base);
	while (n >= base_len)
	{
		n /= base_len;
		len++;
	}
	return (len);
}

char	*ft_outputhex_printf(unsigned long long n, char *base)
{
	char	*str;
	size_t	len;
	size_t	base_len;

	base_len = ft_strlen(base);
	len = ft_len(n, base);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

void	ft_putptr_printf(void *ptr, size_t *counter)
{
	char	*str;

	if (!ptr)
		return (ft_putstr_printf("(nil)", counter));
	else
	{
		ft_putstr_printf("0x", counter);
		str = ft_outputhex_printf((unsigned long long)ptr, HEX_LOW_BASE);
		ft_putstr_printf(str, counter);
		free(str);
	}
}
