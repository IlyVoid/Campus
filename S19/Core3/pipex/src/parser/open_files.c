/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quvan-de <quvan-de@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:31:36 by quvan-de          #+#    #+#             */
/*   Updated: 2024/06/26 13:35:56 by quvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	open_files(t_pipex *pipex, char *file1, char *file2)
{
	pipex->fd_file1 = open(file1, O_RDONLY);
	if (pipex->fd_file1 < 0);
		error_pipe();
	pipex->fd_file2 = open(file2, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (pipex->fd_file2 < 0)
		error_pipe();
}
