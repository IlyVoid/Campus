/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:29:28 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/04 17:29:29 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/ft_printf.h"
#include "../include/libft.h"

void	check_input(int ac, char *file_name)
{
	if (ac != 2)
	{
		ft_printf("Usage: ./fdf <map file>");
		exit(0);
	}
	if (ft_strncmp(file_name + ft_strlen(file_name) - 4, ".fdf", 4) != 0)
	{
		ft_printf("Wrong file extension");
		exit(0);
	}
}

void	map_checker(int width, int height)
{
	if (width == 0 || height == 0)
	{
		ft_printf("Failed to load map. Be sure you tried an existing map\n");
		exit(0);
	}
}
