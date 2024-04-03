/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 11:57:16 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/03 16:26:04 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

size_t	ft_len(unsigned long long n, char *base)
{
	size_t				len;
	unsigned long long	base_len;

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
	int		num_len;
	int		base_len;

	num_len = ft_len(n, base);
	base_len = ft_strlen(base);
	str = ft_calloc((num_len + 1), sizeof(char));
	if (!str)
		return (NULL);
	while (num_len)
	{
		num_len--;
		str[num_len] = base[n % base_len];
		n /= base_len;
	}
	return (str);
}

void	ft_putptr_printf(void *ptr, size_t *counter)
{
	char			*str;
	unsigned long	ptr_add;

	if (!ptr)
	{
		ft_putstr_printf("(null)", counter);
		return ;
	}
	ptr_add = (unsigned long)ptr;
	ft_putstr_printf("0x", counter);
	str = ft_outputhex_printf(ptr_add, HEX_LOW_BASE);
	ft_putstr_printf(str, counter);
	free(str);
}
