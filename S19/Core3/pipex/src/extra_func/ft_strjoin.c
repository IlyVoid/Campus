/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:15:30 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 13:15:55 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;

	if (s1 || s2)
	{
		if (!s2)
			return (ft_strdup((char *)s1));
		if (!s1)
			return (ft_strdup((char *)s2));
		new_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (new_str == NULL)
			return (NULL);
		return (ft_strcat(ft_strcat(new_str, s1), s2));
	}
	return (NULL);
}
