/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 11:56:08 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 11:57:59 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_pipe(void)
{
	char	*error_mssg;

	error_msg = strerror(errno);
	ft_putstr_fd(error_msg, 2);
	ft_putstr_fd("\n", 2);
	exit(errno);
}
