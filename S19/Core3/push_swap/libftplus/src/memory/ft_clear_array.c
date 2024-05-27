/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:08:46 by quvan-de          #+#    #+#             */
/*   Updated: 2024/05/27 13:11:24 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_clear_array(char **array)
{
	int	len;
	int	i;

	len = 0;
	if (!array)
		return ;
	while (array[len])
		len++;
	i = 0;
	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
