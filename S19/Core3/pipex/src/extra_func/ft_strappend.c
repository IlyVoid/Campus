/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:13:36 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 13:25:17 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*ft_strappend(const char *s1, const char *s2, int free_s1, int free_s2)
{
	return (ft_strjoin_free(s1, s2, free_s1, free_s2));
}
