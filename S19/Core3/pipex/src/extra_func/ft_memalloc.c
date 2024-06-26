/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:21:15 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 13:21:34 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	ptr = NULL;
	if (size != 0)
	{
		ptr = (unsigned char *)malloc(sizeof(char) * size);
		if (ptr == NULL)
			ft_error("The malloc from ft_memalloc failed");
		ft_memset(ptr, 0, size);
	}
	else
		ft_error("The memalloc for malloc is egal to 0");
	return ((void *)ptr);
}
