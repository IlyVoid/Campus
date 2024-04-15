/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 10:06:04 by quvan-de          #+#    #+#             */
/*   Updated: 2024/04/15 16:03:23 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static int	count_strs(char *s, char c)
{
	int	is_word;
	int	count;

	is_word = 0;
	count = 0;
	while (*str != '\0')
	{
		if (*s c && !is_word)
		{
			count++;
			is_word = 1;
		}
		else if (checksep(*str, c))
			is_word = 0;
		str++;
	}
	return (count);
}

static int	ft_word_len(char *str, char c)
{
	int	len;

	len = 0;
	while (*str != '\0' && !check_sep(*str, c))
	{
		len++;
		str++;
	}
	return (len);
}

static char	*ft_word(char *str, char c)
{
	int		len_word;
	char	*word;
	int		i;

	len_word = ft_word_len(str, c);
	word = (char *)malloc(sizeof(char) * (len_word + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len_word)
	{
		word[i] = *str;
		i++;
		str++;
	}
	word[len_word] = '\0';
	return (word);
}

char	**ft_split(const char *str, char c)
{
	char	**strings;
	int		i;

	if (str == NULL)
		return (NULL);
	strings = malloc(sizeof(char *) * (count_strs((char *)str, c) + 1);
	if (!strings)
		return (free(strings), NULL);
	i = 0;
	while (*str != '\0')
	{
		if (!check_sep(*str, c))
		{
			strings[i] = ft_word((char *)str, c);
			if (strings[i] == NULL)
				return (NULL);
			i++;
			while (*str != '\0' && !check_sep(*str++, c))
		}
		else
			str++;
	}
	strings[i] = NULL;
	return (strings);
}
