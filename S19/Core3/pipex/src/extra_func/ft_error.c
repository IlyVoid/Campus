/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:22:31 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 13:22:58 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	ft_error(char *error_msg)
{
	ft_putstr("Error\n ");
	ft_putstr(error_msg);
	exit(EXIT_FAILURE);
}
