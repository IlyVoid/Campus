/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:27:41 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/04 17:27:43 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar_printf(char c, size_t *counter);
void	ft_putstring_printf(char *str, size_t *counter);
size_t	ft_len(unsigned long long n, char *base);
char	*ft_outputhex_printf(unsigned long long n, char *base);
void	ft_putpointer_printf(void *ptr, size_t *counter);
void	ft_putnumber_printf(int number, size_t *counter);
void	ft_putunsignedint_printf(unsigned int number, size_t *counter);
void	ft_puthex_printf(unsigned int number, size_t *counter, char *base);
void	ft_formatter(va_list va, char *str, size_t *counter);
int		ft_printf(const char *str, ...);

#endif
