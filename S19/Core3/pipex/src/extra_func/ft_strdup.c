/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:16:43 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 13:17:04 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		i;
	size_t	size;

	size = ft_strlen((char *)s);
	i = 0;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	return (str);
}
