/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_child.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 12:33:56 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 12:55:13 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	create_child(t_pipex *pipex)
{
	pipex->child = (pid_t *)malloc(sizeof(pid_t) * pipex->cmd_nb);
	if (pipex->child == NULL)
		error_pipe();
}
