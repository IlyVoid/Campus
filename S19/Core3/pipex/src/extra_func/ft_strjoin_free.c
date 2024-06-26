/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:14:29 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 13:18:34 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*ft_strjoin_free(const char *s1, const char *s2, int free_s1, int free_s2)
{
	char	*new_str;

	new_str = ft_strjoin(s1, s2);
	if (s1 && free_s1)
		free((void *)s1);
	if (s2 && free_s2)
		free((void *)s2);
	return (new_str);
}
