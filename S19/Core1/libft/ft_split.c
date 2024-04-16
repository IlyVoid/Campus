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
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (check_sep(s[i], c))
			i++;
		else
		{
			count++;
			while (s[i] != '\0' && !check_sep(s[i], c))
				i++;
		}
	}
	return (count);
}

static int	ft_word_len(char *str, char c)
{
	int	len;

	len = 0;
	while (*str != '\0' && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

static char	*ft_word(char *str, char c)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc(sizeof(char) * (ft_word_len(str, c) + 1));
	if (!word)
		return (NULL);
	while (*str != '\0' && *str != c)
	{
		word[i] = *str;
		i++;
		str++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(const char *str, char c)
{
	char	**tab;
	int		i;
	int		j;

	if (!str)
		return (NULL);
	tab = (char **)malloc(sizeof(char *) * (count_strs((char *)str, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (check_sep(str[i], c))
			i++;
		else
		{
			tab[j] = ft_word((char *)&str[i], c);
			if (!tab[j])
				return (ft_free_tab(tab, j));
			j++;
			i += ft_word_len((char *)&str[i], c);
		}
	}
	tab[j] = NULL;
	return (tab);
}
